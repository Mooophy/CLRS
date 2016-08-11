using System;
using System.Collections.Generic;
using System.Linq;

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
                return n == 0 ? 0 : Enumerable
                    .Range(1, n)
                    .Aggregate(int.MinValue, (q, i) => Math.Max(q, p[i - 1] + CutRod(p, n - i)));
            }
        }
    }
}
