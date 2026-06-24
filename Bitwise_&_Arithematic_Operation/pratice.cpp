#include<iostream>
#include<vector>
#include<string>
#include<regex>
#include<algorithm>
#include<curl/curl.h>

using namespace std;

size_t WriteCallback(void* contents, size_t size, size_t nmemb, string* output) {
    output->append((char*)contents, size * nmemb);
    return size * nmemb;
}

string fetchUrl(const string& url) {
    CURL* curl = curl_easy_init();
    string html;

    if (curl) {
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &html);
        curl_easy_perform(curl);
        curl_easy_cleanup(curl);
    }

    return html;
}

void printSecretMessage(const string& url) {
    string html = fetchUrl(url);

    regex rowPattern("<tr[^>]*>(.*?)</tr>", regex::icase);
    regex cellPattern("<t[dh][^>]*>(.*?)</t[dh]>", regex::icase);

    vector<tuple<int, string, int>> data;

    int maxX = 0;
    int maxY = 0;

    auto rowBegin = sregex_iterator(html.begin(), html.end(), rowPattern);
    auto rowEnd = sregex_iterator();

    bool skipHeader = true;

    for (auto it = rowBegin; it != rowEnd; ++it) {
        if (skipHeader) {
            skipHeader = false;
            continue;
        }

        string row = (*it)[1].str();

        vector<string> cells;

        auto cellBegin = sregex_iterator(row.begin(), row.end(), cellPattern);

        for (auto jt = cellBegin; jt != rowEnd; ++jt) {
            string cell = (*jt)[1].str();

            cell = regex_replace(cell, regex("<[^>]+>"), "");
            cells.push_back(cell);
        }

        if (cells.size() != 3) continue;

        try {
            int x = stoi(cells[0]);
            string ch = cells[1];
            int y = stoi(cells[2]);

            data.push_back({x, ch, y});

            maxX = max(maxX, x);
            maxY = max(maxY, y);
        }
        catch (...) {
            continue;
        }
    }

    vector<vector<string>> grid(
        maxY + 1,
        vector<string>(maxX + 1, " ")
    );

    for (auto& [x, ch, y] : data) {
        grid[y][x] = ch;
    }

    for (int y = 0; y <= maxY; y++) {
        for (int x = 0; x <= maxX; x++) {
            cout << grid[y][x];
        }
        cout << '\n';
    }
}

int main() {
    string url =
        "https://docs.google.com/document/d/e/2PACX-1vSvM5gDlNvt7npYHhp_XfsJvuntUhq184By5xO_pA4b_gCWeXb6dM6ZxwN8rE6S4ghUsCj2VKR21oEP/pub";

    printSecretMessage(url);

    return 0;
}