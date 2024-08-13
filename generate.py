# !/usr/bin/python3

from os import path, makedirs
from string import ascii_lowercase, ascii_uppercase


ASCII_DIR = "ascii"
ASCII_STR = 33
ASCII_END =125


def create_empty_file_for_character(ch):
    filename = ch + ".txt"
    filepath = path.join(ASCII_DIR, filename)
    file = open(filepath, "a+")
    file.close()

def get_font_str(str_idx, end_idx, data, lines):
    font_str = ""
    for line in range(0, lines):
        curr_str = ""
        for idx in range (str_idx, end_idx + 1):
            curr_str += data[line][idx]

        font_str += "\n" + curr_str

    # removing '\n' char at beginning
    return font_str[1:]


if __name__ == '__main__':

    for num in range(33, 126):
        print(chr(num), end=' ')
    print()

    if not path.exists(ASCII_DIR):
        makedirs(ASCII_DIR)

    src_file = open("font.txt", "r")
    data = src_file.read()

    data_lines = data.split("\n")

    max_data_lines = len(data_lines) - 1
    max_line_len = len(data_lines[0])

    str_idx = 0
    end_idx = 0

    font_strs = []

    for idx in range(0, max_line_len):

        is_break = True
        for line in range(0, max_data_lines):
            print(line, idx)
            curr_ch = data_lines[line][idx]

            if not (curr_ch == ' '):
                is_break = False
                break

        if not is_break:
            continue

        end_idx = idx - 1

        font_str = get_font_str(str_idx=str_idx, end_idx=end_idx, data=data_lines, lines=max_data_lines)
        font_strs.append(font_str)

        str_idx = idx + 1


    for num in range (ASCII_STR, ASCII_END):
        ch = str(num)
        # create_empty_file_for_character(ch)

        filename = ch + ".txt"
        filepath = path.join(ASCII_DIR, filename)
        file = open(filepath, "w+")

        font_str = font_strs[num - ASCII_STR]
        file.write(font_str)

        file.close()


