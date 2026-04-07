# コンパイラの指定
CC      = gcc
# コンパイルオプション
CFLAGS  = -Wall -g
# 最終的な実行ファイル名
TARGET  = myshell
# ソースファイル
SRCS    = src/main.c

# デフォルトのターゲット
all: $(TARGET)

$(TARGET): $(SRCS)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRCS)

clean:
	rm -f $(TARGET)