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
    DL_HOLD;

    const char *const msg[] = {"1.括符方塊  2.線條箭頭  3.數字標點？(N:下一頁)[Q]",
                               "4.圖案數字  5.希臘字母  6.注音符號？(P:上一頁)[Q]"};
    const char *const ansi[][5][10] =
    {
      {
        {"▁", "▂", "▃", "▄", "▅", "▆", "▇", "█", "◢", "◣"},
        {"▏", "▎", "▍", "▌", "▋", "▊", "▉", "◥", "◤", "（"},
        {"）", "｛", "｝", "〔", "〕", "【", "】", "《", "》", "〈"},
        {"〉", "「", "」", "『", "』", "︻", "︼", "︽", "︾", "︵"},
        {"︶", "︷", "︸", "︹", "︺", "﹁", "﹂", "﹃", "﹄", ""}
      },
      {
        {"┌", "┬", "┐", "├", "┼", "┤", "└", "┴", "┘", "─"},
        {"│", "╭", "╮", "╰", "╯", "▔", "▕", "╱", "╲", "╳"},
        {"═", "╞", "╪", "╡", "／", "＼", "↑", "↓", "←", "→"},
        {"↖", "↗", "↙", "↘", "∥", "∣", "﹉", "﹊", "﹍", "﹎"},
        {"﹋", "︴", "﹏\", "–", "", "", "", "", "", ""}
      },
      {
        {"，", "、", "。", "．", "•", "；", "：", "？", "！", "…"},
        {"‘", "’", "“", "”", "〝", "〞", "＃", "＆", "＊", "※"},
        {"§", "﹡", "＋", "－", "×", "÷", "±", "＜", "＞", "＝"},
        {"≦", "≧", "≠", "∞", "≒", "≡", "∼", "∫", "∮", "♀"},
        {"♂", "∵", "∴", "∩", "∪", "⊥", "∠", "∟", "⊿", ""}
      },
      {
        {"○", "●", "△", "▲", "◎", "☆", "◇", "◆", "□", "■"},
        {"▽", "▼", "㊣", "♁", "☉", "０", "１", "２", "３", "４"},
        {"５", "６", "７", "８", "９", "Ⅰ", "Ⅱ", "Ⅲ", "Ⅳ", "Ⅴ"},
        {"Ⅵ", "Ⅶ", "Ⅷ", "Ⅸ", "Ⅹ", "〡", "〢", "〣", "〤", "〥"},
        {"〦", "〧", "〨", "〩", "十", "卄", "卅", "", "", ""}
      },
      {
        {"Α", "Β", "Γ", "Δ", "Ε", "Ζ", "Η", "Θ", "Ι", "Κ"},
        {"Λ", "Μ", "Ν", "Ξ", "Ο", "Π", "Ρ", "Σ", "Τ", "Υ"},
        {"Φ", "Χ", "Ψ", "Ω", "α\", "β", "γ", "δ", "ε", "ζ"},
        {"η", "θ", "ι", "κ", "λ", "μ", "ν", "ξ", "ο", "π"},
        {"ρ", "σ", "τ", "υ", "φ", "χ", "ψ", "ω", "", ""}
      },
      {
        {"ㄅ", "ㄆ", "ㄇ", "ㄈ", "ㄉ", "ㄊ", "ㄋ", "ㄌ", "ㄍ", "ㄎ"},
        {"ㄏ", "ㄐ", "ㄑ", "ㄒ", "ㄓ", "ㄔ", "ㄕ", "ㄖ", "ㄗ", "ㄘ"},
        {"ㄙ", "ㄚ", "ㄛ", "ㄜ", "ㄝ", "ㄞ", "ㄟ", "ㄠ", "ㄡ", "ㄢ"},
        {"ㄣ", "ㄤ", "ㄥ", "ㄦ", "ㄧ", "ㄨ", "ㄩ", "˙", "ˊ", "ˇ"},
        {"ˋ", "", "", "", "", "", "", "", "", ""}
      }
    };

    char buf[128] = "內碼輸入工具:";
    int ch, i, group, page;

    ch = 'p';
    do
    {
        strcpy(buf + 13, msg[(ch != 'p')]);
        outz(buf);
        ch = vkey();
    }
    while (ch == 'p' || ch == 'n');

    if (ch < '1' || ch > '6')
    {
        DL_RELEASE_VOID();
        return;
    }

    group = ch - '1';
    page = 0;
    for (;;)
    {
        buf[0] = '\0';

        for (i = 0; i < 10; i++)
        {
            sprintf(buf + strlen(buf), "%d%s%s ", i, ".", ansi[group][page][i]);
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
        else
        {
            if (ch >= '0' && ch <= '9')
                ve_string(ansi[group][page][ch - '0']);
            break;
        }
    }
    DL_RELEASE_VOID();
}
