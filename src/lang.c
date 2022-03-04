#include "include/opl.h"
#include "include/lang.h"
#include "include/util.h"
#include "include/fntsys.h"
#include "include/ioman.h"
#include "include/themes.h"

// Language support
static char *internalEnglish[LANG_STR_COUNT] = {
    "繁體中文 (內置)",
    "Open PS2 Loader %s",
    "保存設置",
    "返回",
    "網路設置",
    "進階設置",
    "<無數值>",
    "設置保存到 %s",
    "寫入設置錯誤!",
    "離開",
    "設置",
    "選單",
    "USB 遊戲",
    "HDD 遊戲",
    "ETH 遊戲",
    "應用程式",
    "主題",
    "語言",
    "系統電源將會關閉.",
    "退出到瀏覽界面?",
    "取消更新?",
    "%d: 偵測不到硬碟",
    "%d: 硬碟沒有格式化",
    "%d: 啟動網路錯誤",
    "%d: 偵測不到網卡",
    "%d: 無法連接 SMB 伺服器",
    "%d: 無法登入 SMB 伺服器",
    "%d: 無法開啟 SMB 共享",
    "%d: 無法羅列 SMB 共享清單",
    "%d: 無法列出遊戲清單",
    "%d: DHCP 伺服器不存在",
    "%d: 無網絡連接",
    "開啟",
    "關閉",
    "確定",
    "選擇",
    "取消",
    "圓圈",
    "叉叉",
    "遊戲清單",
    "遊戲設置",
    "刪除設置",
    "移除遊戲所有的設置",
    "滾動",
    "較慢",
    "中等",
    "較快",
    "預設選單",
    "從光碟中讀取",
    "請稍後",
    "讀取 Game ID 時出錯",
    "自動排序",
    "讀取語言文件時出錯",
    "禁用偵錯顏色",
    "無偵測到搖桿, 等待中...",
    "啟用圖示封面",
    "寬螢幕",
    "關機",
    "設置讀取中...",
    "設置儲存中...",
    "啟動裝置",
    "重新整理",
    "BDM 裝置啟動模式",
    "HDD 裝置啟動模式",
    "ETH 裝置啟動模式",
    "應用程式啟動模式",
    "自動",
    "手動",
    "啟動 HDL 服務",
    "HDL 服務啟動中...",
    "HDL 服務正在運行...",
    "啟動 HDL 服務時出錯.",
    "HDL 服務未能讀取...",
    "IGR 路徑",
    "背景顏色",
    "文字顏色",
    "- PS2 -",
    "- SMB 伺服器 -",
    "IP 位置模式",
    "靜態",
    "DHCP",
    "IP 位置",
    "位置",
    "子網路遮罩",
    "閘道",
    "DNS 伺服器",
    "端口",
    "共享",
    "使用者",
    "密碼",
    "<無設置>",
    "位置格式",
    "IP",
    "NetBIOS",
    "允許",
    "項目將被永久刪除, 繼續嗎?",
    "重新命名",
    "刪除",
    "運行",
    "顯示設置",
    "啟用刪除與重新命名功能",
    "記住最後一個玩的遊戲",
    "選定鍵",
    "錯誤, 遊戲有碎片.",
    "錯誤, 無法運行該項目.",
    "測試修改",
    "GUEST驗證留空.",
    "精確讀取",
    "同步模式",
    "脫開系統調用",
    "跳過 Videos",
    "模擬 DVD-DL",
    "禁用 IGR",
    "空閑",
    "空閑",
    "改變大小將會重新格式化 VMC",
    "生成",
    "開始",
    "變更",
    "放棄",
    "重置",
    "使用通用",
    "設置 VMC",
    "名稱",
    "大小",
    "狀態",
    "進度",
    "VMC 檔案已存在.",
    "無效的 VMC 檔案, 大小有誤.",
    "需要建立 VMC 檔案.",
    "訪問 VMC %s 出錯。繼續使用插槽 %d 中的記憶卡 %d?",
    "自動重新整理",
    "關於",
    "程序",
    "測試",
    "BDM 前墜路徑",
    "自定義IGR啟動文件.",
    "數值以分鐘計,設為 0 禁用降速.",
    "自動 HDD 降速",
    "影片模式",
    "對話框顏色",
    "被選定顏色",
    "重置顏色",
    "資訊",
    "自定義 ELF",
    "顏色選項",
    "重新連線",
    "留空列出共享清單.",
    "ETH 前墜位置",
    "退格",
    "空格",
    "Enter",
    "模式",
    "VMC 插槽 1",
    "VMC 插槽 2",
    "遊戲 ID",
    "DMA 模式",
    "垂直同步",
    "模式 1",
    "模式 2",
    "模式 3",
    "模式 4",
    "模式 5",
    "模式 6",
    "模式 7",
    "模式 8",
    "設置 GSM",
    "以太網鏈接模式",
    "100Mbit 全雙工",
    "100Mbit 半雙工",
    "10Mbit 全雙工",
    "10Mbit 半雙工x",
    "GSM 設置",
    "啟用 GSM",
    "T切換 GSM 開或關",
    "畫面模式",
    "強制自定義顯示模式.",
    "水平調整",
    "調整水平方向的顯示位置.",
    "垂直調整",
    "調整垂直方向的顯示位置.",
    "過掃",
    "過掃調節.",
    "跳過 FMV",
    "跳過全動態視頻.",
    "金手指設置",
    "啟用 PS2RD 金手指引擎",
    "允許 PS2RD 金手指引擎對你的遊戲進行補丁.",
    "PS2RD 金手指引擎模式",
    "自動選擇或選擇遊戲金手指.",
    "自動選擇金手指",
    "選擇遊戲金手指",
    "錯誤: 讀取金手指文件出錯.",
    "無發現金手指文件.",
    "下載預設值",
    "網路更新",
    "覆蓋現有記錄",
    "更新失敗.",
    "連結更新伺服器失敗.",
    "更新已完成.",
    "更新已取消.",
    "從網路上下載設置?",
    "自定義設置",
    "已下載預設值",
    "將自動於 %i 秒後啟動...",
    "自動啟動",
    "以秒為單位,設為 0 來禁用自動啟動.",
    "PS2 標誌",
    "顯示與控制台區域匹配的有效光碟標誌.",
    "配置PADEMU",
    "PADEMU設置",
    "開啟PADEMU",
    "為選定遊戲開啟/關閉PADEMU調節.",
    "連接模式",
    "選擇PADEMU連接模式.",
    "DualShock3/4 USB 連接",
    "DualShock3/4 藍牙連接",
    "設置埠:",
    "選擇應用PADEMU埠.",
    "開啟模擬",
    "打開/關閉選定埠的模擬.",
    "開啟振動",
    "打開/關閉選定埠的振動.",
    "藍牙適配器 MAC 地址:",
    "DS手柄 MAC地址:",
    "配對",
    "配對 DS 手柄,
    "藍牙適配器和DS手柄進行MAC地址配對.",
    "沒有連接",
    "藍牙適配器訊息",
    "顯示更多的訊息和支援的特性",
    "HCI 版本:",
    "LMP 版本:",
    "製造商 ID:",
    "支援的功能:",
    "是",
    "否",
    "Bluetooth adapter should be fully compatible with DS3/DS4 controllers.",
    "Bluetooth adapter may not work correctly with DS3/DS4 controllers.",
    "Enable Multitap Emulation",
    "Turns on/off Multitap emulation for selected game.",
    "Multitap Emulator On Port:",
    "Select port for Multitap emulation.",
    "Disable Fake DS3 Workaround",
    "Some fake DS3s need workaround, this option will disable it.",
    "Emulate FIELD Flipping",
    "Fix for games that glitch under progressive video modes.",
    "Parental Lock Settings",
    "Parental Lock Password",
    "Leave blank to disable the parental lock.",
    "Enter Parental Lock Password",
    "Parental lock password incorrect.",
    "Parental lock disabled.",
    "Build Options:",
    "Error - this password cannot be used.",
    "VMC %s file is fragmented. Continue with Memory Card in slot %d?",
    "Audio Settings",
    "Enable Sound Effects",
    "Enable Boot Sound",
    "Sound Effects Volume",
    "Boot Sound Volume",
    "Confirm video mode change?",
    "Cache Game List (HDD)",
    "Enable Notifications",
    "%s loaded from %s",
    "Options",
    "Game settings saved.",
    "%s settings removed.",
    "Overwrites existing game compatibility settings when enabled.",
    "Settings Mode",
    "Global",
    "Per Game",
    "All",
    "Select settings to remove.",
    "Support Forums:",
    "Title",
    "Genre",
    "Release",
    "Developer",
    "Description",
    "BDM Games",
    "Select Block Devices",
};

static int guiLangID = 0;
static char **lang_strs = internalEnglish;
static int nValidEntries = LANG_STR_COUNT;

static int nLanguages = 0;
static language_t languages[MAX_LANGUAGE_FILES];
static char **guiLangNames;

// localised string getter
char *_l(unsigned int id)
{
    return lang_strs[id];
}

static void lngFreeFromFile(char **lang_strs)
{
    if (guiLangID == 0)
        return;

    int strId = 0;
    for (; strId < nValidEntries; strId++) {
        free(lang_strs[strId]);
        lang_strs[strId] = NULL;
    }
    free(lang_strs);
    lang_strs = NULL;
}

static int lngLoadFont(const char *dir, const char *name)
{
    char path[256];

    snprintf(path, sizeof(path), "%sfont_%s.ttf", dir, name);
    LOG("LANG Custom TTF font path: %s\n", path);
    if (fntLoadDefault(path) == 0)
        return 0;

    snprintf(path, sizeof(path), "%sfont_%s.otf", dir, name);
    LOG("LANG Custom OTF font path: %s\n", path);
    if (fntLoadDefault(path) == 0)
        return 0;

    LOG("LANG cannot load font.\n");

    return -1;
}

static int lngLoadFromFile(char *path, char *name)
{
    char dir[128];

    file_buffer_t *fileBuffer = openFileBuffer(path, O_RDONLY, 1, 1024);
    if (fileBuffer) {
        // file exists, try to read it and load the custom lang
        char **curL = lang_strs;
        char **newL = (char **)calloc(LANG_STR_COUNT, sizeof(char *));

        int strId = 0;
        while (strId < LANG_STR_COUNT && readFileBuffer(fileBuffer, &newL[strId])) {
            strId++;
        }
        closeFileBuffer(fileBuffer);

        LOG("LANG Loaded %d entries\n", strId);

        int newEntries = strId;
        // if necessary complete lang with default internal
        while (strId < LANG_STR_COUNT) {
            LOG("LANG Default entry added: %s\n", internalEnglish[strId]);
            newL[strId] = internalEnglish[strId];
            strId++;
        }
        lang_strs = newL;
        lngFreeFromFile(curL);

        // remember how many entries were read from the file (for the free later)
        nValidEntries = newEntries;

        int len = strlen(path) - strlen(name) - 9; // -4 for extension,  -5 for prefix
        memcpy(dir, path, len);
        dir[len] = '\0';

        lngLoadFont(dir, name);

        return 1;
    }
    return 0;
}

char *lngGetValue(void)
{
    return guiLangNames[guiLangID];
}

static int lngReadEntry(int index, const char *path, const char *separator, const char *name, unsigned int mode)
{
    if (!S_ISDIR(mode)) {
        if (strstr(name, ".lng") || strstr(name, ".LNG")) {

            language_t *currLang = &languages[nLanguages + index];

            // filepath for this language file
            int length = strlen(path) + 1 + strlen(name) + 1;
            currLang->filePath = (char *)malloc(length * sizeof(char));
            sprintf(currLang->filePath, "%s%s%s", path, separator, name);

            // extract name for this language (will be used for the English translation)
            length = strlen(name) - 5 - 4 + 1;
            currLang->name = (char *)malloc(length * sizeof(char));
            memcpy(currLang->name, name + 5, length);
            currLang->name[length - 1] = '\0';

            /*file_buffer_t* fileBuffer = openFileBuffer(currLang->filePath, 1, 1024);
            if (fileBuffer) {
                // read localized name of language from file
                if (readLineContext(fileBuffer, &currLang->name))
                    readLineContext(fileBuffer, &currLang->fontName);
                closeFileBuffer(fileBuffer);
            }*/

            index++;
        }
    }
    return index;
}

static void lngRebuildLangNames(void)
{
    if (guiLangNames)
        free(guiLangNames);

    // build the languages name list
    guiLangNames = (char **)malloc((nLanguages + 2) * sizeof(char **));

    // add default internal (english)
    guiLangNames[0] = internalEnglish[0];

    int i = 0;
    for (; i < nLanguages; i++) {
        guiLangNames[i + 1] = languages[i].name;
    }

    guiLangNames[nLanguages + 1] = NULL;
}

int lngAddLanguages(char *path, const char *separator, int mode)
{
    int result;

    result = listDir(path, separator, MAX_LANGUAGE_FILES - nLanguages, &lngReadEntry);
    nLanguages += result;
    lngRebuildLangNames();

    const char *temp;
    if (configGetStr(configGetByType(CONFIG_OPL), "language_text", &temp)) {
        if (lngSetGuiValue(lngFindGuiID(temp)))
            moduleUpdateMenu(mode, 0, 1);
    }

    return result;
}

void lngInit(void)
{
    fntInit();

    lngAddLanguages(gBaseMCDir, "/", -1);
}

void lngEnd(void)
{
    lngFreeFromFile(lang_strs);

    int i = 0;
    for (; i < nLanguages; i++) {
        free(languages[i].name);
        free(languages[i].filePath);
    }

    free(guiLangNames);

    fntEnd();
}

int lngSetGuiValue(int langID)
{
    if (langID != -1) {
        if (guiLangID != langID) {
            if (langID != 0) {
                language_t *currLang = &languages[langID - 1];
                if (lngLoadFromFile(currLang->filePath, currLang->name)) {
                    guiLangID = langID;
                    thmSetGuiValue(thmGetGuiValue(), 1);
                    return 1;
                }
            }
            lang_strs = internalEnglish;
            guiLangID = 0;
            // lang switched back to internalEnglish, reload default font
            fntLoadDefault(NULL);
            thmSetGuiValue(thmGetGuiValue(), 1);
        }
    }
    return 0;
}

int lngGetGuiValue(void)
{
    return guiLangID;
}

int lngFindGuiID(const char *lang)
{
    if (lang) {
        int i = 0;
        for (; i < nLanguages; i++) {
            if (strcasecmp(languages[i].name, lang) == 0)
                return i + 1; // shift for Gui id
        }
    }
    return 0;
}

char **lngGetGuiList(void)
{
    return guiLangNames;
}

char *lngGetFilePath(int langID)
{
    language_t *currLang = &languages[langID - 1];
    char *path = currLang->filePath;

    return path;
}
