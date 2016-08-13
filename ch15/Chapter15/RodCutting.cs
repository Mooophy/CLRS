using System.Collections.Generic;
using System.Linq;
using static System.Linq.Enumerable;
using static System.Math;

namespace Chapter15
{
    namespace RodCutting
    {
        public static class Algorithms
        {
            /// <summary>
            /// O(2^n)
            /// </summary>
            /// <param name="p">Prices</param>
            /// <param name="n">Length</param>
            /// <returns>Maximum revenue</returns>
            public static int CutRod(IList<int> p, int n)
            {
                return n == 0 ? 0 : Range(1, n)
                    .Select(i => p[i - 1] + CutRod(p, n - i))
                    .Max();
            }
            /// <summary>
            /// O(n^2), The Top Down DP.
            /// </summary>
            /// <param name="p">Prices</param>
            /// <param name="n">Length</param>
            /// <returns></returns>
            public static int MemoizedCutRod(IList<int> p, int n)
            {
                return MemoizedCutRodAux(
                        p,
                        n,
                        Range(0, n + 1).Select(i => int.MinValue).ToList()
                    );
            }

            private static int MemoizedCutRodAux(IList<int> p, int n, IList<int> r)
            {
                if (r[n] >= 0)
                    return r[n];
                if (n == 0)
                    return r[0] = 0;
                return r[n] = Range(1, n)
                    .Select(i => p[i - 1] + MemoizedCutRodAux(p, n - i, r))
                    .Max();
            }
            /// <summary>
            /// O(n^2), The Bottom Up DP.
            /// </summary>
            /// <param name="p">Prices</param>
            /// <param name="n">Length</param>
            /// <returns></returns>
            public static int BottomUpCutRod(IList<int> p, int n)
            {
                return Range(1, n)
                    .Aggregate(
                        new[] { 0 }.AsEnumerable(),
                        (r, j) => r.Concat(new[] { Range(1, j).Select(i => p[i - 1] + r.ElementAt(j - i)).Max() })
                    )
                    .Last();
            }
        }
    }
}
