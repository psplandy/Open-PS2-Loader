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
    "Coders",
    "Quality Assurance",
    "BDM Prefix Path",
    "Boots custom ELF after an IGR.",
    "Value in minute(s), 0 to disable spin down.",
    "Automatic HDD Spin Down",
    "Video Mode",
    "Dialog Color",
    "Selected Color",
    "Reset Colors",
    "Info",
    "Custom ELF",
    "Color Selection",
    "Reconnect",
    "Leave empty to list shares.",
    "ETH Prefix Path",
    "Backspace",
    "Space",
    "Enter",
    "Mode",
    "VMC Slot 1",
    "VMC Slot 2",
    "Game ID",
    "DMA Mode",
    "V-Sync",
    "Mode 1",
    "Mode 2",
    "Mode 3",
    "Mode 4",
    "Mode 5",
    "Mode 6",
    "Mode 7",
    "Mode 8",
    "Configure GSM",
    "Ethernet Link Mode",
    "100Mbit Full-duplex",
    "100Mbit Half-duplex",
    "10Mbit Full-duplex",
    "10Mbit Half-duplex",
    "GSM Settings",
    "Enable GSM",
    "Toggles GSM on/off.",
    "VMODE",
    "Forced custom display mode.",
    "H-POS",
    "Horizontal adjustment.",
    "V-POS",
    "Vertical adjustment.",
    "Overscan",
    "Overscan adjustment.",
    "FMV Skip",
    "Skips full motion videos.",
    "Cheat Settings",
    "Enable PS2RD Cheat Engine",
    "Lets PS2RD Cheat Engine patch your game.",
    "PS2RD Cheat Engine Mode",
    "Auto select or select game cheats.",
    "Auto Select Cheats",
    "Select Game Cheats",
    "Error: failed to load cheat file.",
    "No cheats found.",
    "Download Defaults",
    "Network Update",
    "Overwrite Existing Records",
    "Update failed.",
    "Failed to connect to update server.",
    "Update completed.",
    "Update cancelled.",
    "Download settings from the network?",
    "Customized Settings",
    "Downloaded Defaults",
    "Auto start in %i s...",
    "Auto Start",
    "Value in second(s), 0 to disable auto start.",
    "PS2 Logo",
    "Displayed for a valid disc logo matching the console's region.",
    "Configure PADEMU",
    "Pad Emulator Settings",
    "Enable Pad Emulator",
    "Turns on/off Pad Emulator for selected game.",
    "Pad Emulator Mode",
    "Select Pad Emulator mode.",
    "DualShock3/4 USB",
    "DualShock3/4 BT",
    "Settings For Port:",
    "Select Pad Emulator port for settings.",
    "Enable Emulation",
    "Turns on/off Pad Emulator for selected port.",
    "Enable Vibration",
    "Turns on/off vibration for Pad Emulator selected port.",
    "USB Bluetooth Adapter MAC Address:",
    "DS Controller Paired To MAC Address:",
    "Pair",
    "Pair DS Controller",
    "Pair DS controller with Bluetooth adapter MAC address.",
    "Not Connected",
    "Bluetooth Adapter Information",
    "Shows more information and supported features.",
    "HCI Version:",
    "LMP Version:",
    "Manufacturer ID:",
    "Supported Features:",
    "Yes",
    "No",
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
