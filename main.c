/*
 * 挿入法を使った整数整列を行う。
 *  使い方：usage()参照。
 */

#include<stdio.h>
#include<stdlib.h>
#include"insertSort.h"

// 10進法
#define BASE 10

void
usage(void)
{
    printf("./main 整列対象の整数リスト\n");
    printf("e.g. ./main 3 8 4\n");
}

void
printList( long *list, int size )
{
    int _i = 0;

    for( _i = 0; _i < size; _i++ )
    {
        printf("%ld ", list[_i+1]);
    }
    printf("\n");
}

int
main( int argc, char** argv )
{

    long *_list     = NULL;
    int  _i         = 0;
    char *_endptr   = NULL;

    if( argc < 2 )
    {
        usage();
        exit(EXIT_FAILURE);
    }

    _list = (long *)calloc( argc, sizeof(long) );
    if( NULL == _list )
    {
        printf("メモリ獲得エラー\n");
        exit(EXIT_FAILURE);
    }

    // 数値へ変換
    for( _i = 0; _i < argc - 1; _i++ )
    {
        _list[_i+1] = strtol( argv[_i+1], &_endptr, BASE );
    }

    printList( _list, argc - 1 );

    insertSort( _list, argc );

    printList( _list, argc - 1 );

    return 0;
}
