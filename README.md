挿入法によるlong型整数の整列を行うプログラムを作成した。  
そのときの生成物を置く。  

# ファイル概要
 main.c     挿入法を使った整列を行う。  
 insertSort.c   挿入法本体  
 test_insertSort.c  挿入法のテストプログラム

# 必要なもの
CUnit  
mudflap  

# 必要なもののインストール方法
$ sudo apt-get install CUnit  
$ sudo apt-get install libmudflap0-4.6

# ビルド方法 ＆ 実行方法
 1. $ ./configure  
 2. $ make  
 3. $ ./main 3 8 4

# テストプログラム実行方法
 1. $ ./configure  
 2. $ make check  
 3. $ ./test_insertSort
