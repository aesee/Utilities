# входной файл
inputText = open('text.txt', 'r')
# выходной файл
outputBin = open('output.bin', 'wb')

# каждая строка файла делится по 8 разрядов
# и записывается в бинарный файл
for line in inputText:
    for i in range(len(line)//8):
        word = line[i*8:8+i*8]
        wordNew = bytes([int(word, 2)])
        outputBin.write(wordNew)

# завершение работы с файлами
inputText.close()
outputBin.close()
