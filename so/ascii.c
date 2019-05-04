/*-------------------------------------------------------*/
/* so/ascii.c                                            */
/*-------------------------------------------------------*/
/* author : weichung.bbs@bbs.ntit.edu.tw                 */
/* target : 符號輸入工具                                 */
/* create : 99/10/27                                     */
/* update : 2000/07/14                                   */
/*-------------------------------------------------------*/

#include "bbs.h"

void
input_tools(void)
{
    const char msg1[] = {"1.括符方塊  2.線條箭頭  3.數字標點？(N:下一頁)[Q]"};
    const char msg2[] = {"4.圖案數字  5.希臘字母  6.注音符號？(P:上一頁)[Q]"};
    const char *ansi1[5][10] =
    {
        {"▁", "▂", "▃", "▄", "▅", "▆", "▇", "█", "◢", "◣"},
        {"▏", "▎", "▍", "▌", "▋", "▊", "▉", "◥", "◤", "（"},
        {"）", "｛", "｝", "〔", "〕", "【", "】", "《", "》", "〈"},
        {"〉", "「", "」", "『", "』", "︻", "︼", "︽", "︾", "︵"},
        {"︶", "︷", "︸", "︹", "︺", "﹁", "﹂", "﹃", "﹄", ""}
    };

    const char *ansi2[5][10] =
    {
        {"┌", "┬", "┐", "├", "┼", "┤", "└", "┴", "┘", "─"},
        {"│", "╭", "╮", "╰", "╯", "▔", "▕", "╱", "╲", "╳"},
        {"═", "╞", "╪", "╡", "／", "＼", "↑", "↓", "←", "→"},
        {"↖", "↗", "↙", "↘", "∥", "∣", "﹉", "﹊", "﹍", "﹎"},
        {"﹋", "︴", "﹏\", "–", "", "", "", "", "", ""}
    };

    const char *ansi3[5][10] =
    {
        {"，", "、", "。", "．", "•", "；", "：", "？", "！", "…"},
        {"‘", "’", "“", "”", "〝", "〞", "＃", "＆", "＊", "※"},
        {"§", "﹡", "＋", "－", "×", "÷", "±", "＜", "＞", "＝"},
        {"≦", "≧", "≠", "∞", "≒", "≡", "∼", "∫", "∮", "♀"},
        {"♂", "∵", "∴", "∩", "∪", "⊥", "∠", "∟", "⊿", ""}
    };

    const char *ansi4[5][10] =
    {
        {"○", "●", "△", "▲", "◎", "☆", "◇", "◆", "□", "■"},
        {"▽", "▼", "㊣", "♁", "☉", "０", "１", "２", "３", "４"},
        {"５", "６", "７", "８", "９", "Ⅰ", "Ⅱ", "Ⅲ", "Ⅳ", "Ⅴ"},
        {"Ⅵ", "Ⅶ", "Ⅷ", "Ⅸ", "Ⅹ", "〡", "〢", "〣", "〤", "〥"},
        {"〦", "〧", "〨", "〩", "十", "卄", "卅", "", "", ""}
    };

    const char *ansi5[5][10] =
    {
        {"Α", "Β", "Γ", "Δ", "Ε", "Ζ", "Η", "Θ", "Ι", "Κ"},
        {"Λ", "Μ", "Ν", "Ξ", "Ο", "Π", "Ρ", "Σ", "Τ", "Υ"},
        {"Φ", "Χ", "Ψ", "Ω", "α\", "β", "γ", "δ", "ε", "ζ"},
        {"η", "θ", "ι", "κ", "λ", "μ", "ν", "ξ", "ο", "π"},
        {"ρ", "σ", "τ", "υ", "φ", "χ", "ψ", "ω", "", ""}
    };

    const char *ansi6[5][10] =
    {
        {"ㄅ", "ㄆ", "ㄇ", "ㄈ", "ㄉ", "ㄊ", "ㄋ", "ㄌ", "ㄍ", "ㄎ"},
        {"ㄏ", "ㄐ", "ㄑ", "ㄒ", "ㄓ", "ㄔ", "ㄕ", "ㄖ", "ㄗ", "ㄘ"},
        {"ㄙ", "ㄚ", "ㄛ", "ㄜ", "ㄝ", "ㄞ", "ㄟ", "ㄠ", "ㄡ", "ㄢ"},
        {"ㄣ", "ㄤ", "ㄥ", "ㄦ", "ㄧ", "ㄨ", "ㄩ", "˙", "ˊ", "ˇ"},
        {"ˋ", "", "", "", "", "", "", "", "", ""}
    };

    char buf[128] = "內碼輸入工具:", tmp[5];
    char *show[5][10];
    int ch, i, page;

    ch = 'p';
    do
    {
        strcpy(buf + 13, (ch == 'p') ? msg1 : msg2);
        outz(buf);
        ch = vkey();
    }
    while (ch == 'p' || ch == 'n');

    if (ch < '1' || ch > '6')
        return;

    switch (ch)
    {
    case '1':
        memcpy(show, ansi1, sizeof(show));
        break;
    case '2':
        memcpy(show, ansi2, sizeof(show));
        break;
    case '3':
        memcpy(show, ansi3, sizeof(show));
        break;
    case '4':
        memcpy(show, ansi4, sizeof(show));
        break;
    case '5':
        memcpy(show, ansi5, sizeof(show));
        break;
    case '6':
        memcpy(show, ansi6, sizeof(show));
        break;
    }

    page = 0;
    for (;;)
    {
        buf[0] = '\0';

        for (i = 0; i < 10; i++)
        {
            sprintf(tmp, "%d%s%s ", i, ".", show[page][i]);
            strcat(buf, tmp);
        }
        strcat(buf, "(P:上  N:下)[Q]");
        outz(buf);
        ch = vkey();

        if (ch == 'p')
        {
            if (page)
                page -= 1;
        }
        else if (ch == 'n')
        {
            if (page != 4)
                page += 1;
        }
        else if (ch < '0' || ch > '9')
        {
            buf[0] = '\0';
            break;
        }
        else
        {
            ve_string(show[page][ch - '0']);
            break;
        }
        buf[0] = '\0';
    }
}
