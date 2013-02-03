#include "insertSort.h"

/*
 * 挿入関数
 *  挿入位置を探し、挿入する。
 *  ただし、それまで比較したデータはずらす
 *  IN
 *      @arg    ary     整列対象配列の先頭ポインタ
 *              idx     挿入対象の配列インデックス
 *              tmp     番兵
 */
STATIC inline void
_insertSort( long *ary, int idx, long tmp )
{
    // 番兵との比較
    while( tmp < ary[idx] )
    {
        // データをずらす
        ary[idx+1]  = ary[idx];
        // 次の比較対象へ移動
        idx         = idx - 1;
    }
    // 挿入
    ary[idx+1] = tmp;
}

/*
 * 挿入法
 *  IN
 *      @arg    ary     整列対象配列の先頭ポインタ
 *              size    整列対象配列の大きさ(番兵含む)
 *  OUT
 *      @arg    ary     整列対象配列の先頭ポインタ(整列後)
 */
void
insertSort( long *ary, int size )
{
    int _i   = 0;
    int _j   = 0;

    // 挿入対象のデータを選択し、挿入法を適用する
    for( _i = 2; _i < size; _i++ )
    {
        // 挿入対象を番兵へ代入する
        ary[0]  = ary[_i];

        // 挿入法を適用する
        _j      = _i - 1;
        _insertSort( ary, _j, ary[0] );
    }
}
