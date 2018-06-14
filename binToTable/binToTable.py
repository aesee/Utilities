#!/usr/bin/python
import sys
import io
import re
import struct
import binascii

# Settings
STYLE = "table{ border: 1px black;\n border-collapse: collapse }\n" + \
        "td, th { border: solid 7px black; padding: 2px; } \n" + \
        "tr:first-child { background-color: #D3D3D3; }" + \
        "p { margin-top: -1em; }" + \
        "html { font-size: 2.5em !important; }"
NAME_OF_TABLE = "Test Log"


# Functions
def toDouble(number):
    number = changeOrder(number)
    number = bytes(number, 'UTF-8')
    return str(struct.unpack("d", binascii.unhexlify(number)))

def changeOrder(number):
    newNumber = ""
    i = len(number)
    while i > 0:
        newNumber = newNumber + number[i-2] + number[i-1]
        i = i - 2
    return newNumber

#test = '7FF8000000000000'
#print("---")
#print(toDouble(test))
#print("---")

def table(text):
    return "<table>" + text + "</table>\n"


def head(text):
    return "<head>" + text + "</head>\n"


def body(text):
    return "<body>" + text + "</body>\n"


def indent(text):
    return "<p>" + text + "</p>\n"


def row(line, needParse = True):
    text = ""
    if not (re.match(r'\s*\r?\n', line)):
        if needParse:
            wordsInLine = re.split(r'\t+', line)
            if len(wordsInLine) == 1:
                return indent(wordsInLine[0])
            for word in wordsInLine:
                if re.findall(r'0x',word) and len(word) == 18:              # maybe change to replace (if it returns true)
                    word = word + "\n" + toDouble(word[2:])
                text += cell(word)
        else:
            text = line
        return "\n<tr>" + text + "</tr>\n"
    else:
        return "</table><br><table>"


def cell(text):
    if re.match(r'.',text):
        return "<td>" + text + "</td>"
    else:
        return ""

# Constants
HTML_BEGINNING = "<!DOCTYPE html>\n<html>\n" + head("<meta charset=\"utf-8-sig\"><title>" + NAME_OF_TABLE + "</title>\n<style>" + STYLE + "</style>\n") + "\n<body>\n"
TABLE_BEGINNING = "<table>\n"

# Script
fileName = str(sys.argv[1])
newFile = fileName.replace(".bin", ".html")

with io.open(fileName, "r", encoding='utf-8-sig') as originalFile, open(newFile, "w+") as table:
    table.write(HTML_BEGINNING + TABLE_BEGINNING)
    for line in originalFile:
        table.write(row(line))
    table.write("</table>\n</body>\n</html>")

# Closing
originalFile.close()
table.close()
