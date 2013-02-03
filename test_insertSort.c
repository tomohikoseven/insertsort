#include<CUnit/CUnit.h>
#include<CUnit/Console.h>

#include "insertSort.h"

extern inline void _insertSort( long *ary, int idx, int tmp );

void
test__insertSort01(void)
{
    long _ary[3];

    memset( _ary, 0x00, sizeof( _ary ) );
    _ary[0] = 0;
    _ary[1] = 1;
    _ary[2] = 2;

    _ary[0] = _ary[2];
    _insertSort( _ary, 1, _ary[0] );

    CU_ASSERT_EQUAL( 1, _ary[1] );
    CU_ASSERT_EQUAL( 2, _ary[2] );

}

void
test__insertSort02(void)
{
    long _ary[3];

    memset( _ary, 0x00, sizeof( _ary ) );
    _ary[0] = 0;
    _ary[1] = 2;
    _ary[2] = 1;

    _ary[0] = _ary[2];
    _insertSort( _ary, 1, _ary[0] );

    CU_ASSERT_EQUAL( 1, _ary[1] );
    CU_ASSERT_EQUAL( 2, _ary[2] );

}

void
test__insertSort03(void)
{
    long _ary[4];

    memset( _ary, 0x00, sizeof( _ary ) );
    _ary[0] = 0;
    _ary[1] = 1;
    _ary[2] = 3;
    _ary[3] = 2;

    _ary[0] = _ary[3];
    _insertSort( _ary, 2, _ary[0] );

    CU_ASSERT_EQUAL( 2, _ary[0] );
    CU_ASSERT_EQUAL( 1, _ary[1] );
    CU_ASSERT_EQUAL( 2, _ary[2] );
    CU_ASSERT_EQUAL( 3, _ary[3] );
}

void
test_insertSort01(void)
{
    long ary[3];

    // pre
    memset( ary, 0x00, sizeof(ary) );
    ary[0] = 0;
    ary[1] = 1;
    ary[2] = 2;

    insertSort( ary, sizeof(ary)/sizeof(ary[0]) );
    CU_ASSERT_EQUAL( 1, ary[1] );
    CU_ASSERT_EQUAL( 2, ary[2] );
}

void
test_insertSort02(void)
{
    long ary[4];

    // pre
    memset( ary, 0x00, sizeof(ary) );
    ary[0] = 0;
    ary[1] = 3;
    ary[2] = 1;
    ary[3] = 2;

    insertSort( ary, sizeof(ary)/sizeof(ary[0]) );
    CU_ASSERT_EQUAL( 1, ary[1] );
    CU_ASSERT_EQUAL( 2, ary[2] );
    CU_ASSERT_EQUAL( 3, ary[3] );
}

int
main(void)
{
    CU_pSuite   _tSuite_insertSort;
    CU_pSuite   _tSuite__insertSort;

    CU_initialize_registry();

    // テストスイート
    _tSuite_insertSort
                = CU_add_suite("test_insertSort", NULL, NULL);
    _tSuite__insertSort
                = CU_add_suite("test__insertSort", NULL, NULL);

    // テストケース
    CU_add_test(    _tSuite__insertSort,
                    "test__insertSort01",
                    test__insertSort01      );
    CU_add_test(    _tSuite__insertSort,
                    "test__insertSort02",
                    test__insertSort02      );
    CU_add_test(    _tSuite__insertSort,
                    "test__insertSort03",
                    test__insertSort03      );

    CU_add_test(    _tSuite_insertSort,
                    "test_insertSort01",
                    test_insertSort01      );
    CU_add_test(    _tSuite_insertSort,
                    "test_insertSort02",
                    test_insertSort02      );

    // テスト実行
    CU_console_run_tests();
    // テストレジストリ削除
    CU_cleanup_registry();

    return 0;
}
