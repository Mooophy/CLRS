using Microsoft.VisualStudio.TestTools.UnitTesting;
using Chapter15.RodCutting;

namespace UnitTest
{
    [TestClass]
    public class RodCuttingTests
    {
        [TestMethod]
        public void CutRod()
        {
            var ps = new[] { 1, 5, 8, 9, 10, 17, 17, 20, 24, 30 };
            Assert.AreEqual(30, Algorithms.CutRod(ps, ps.Length - 0));
            Assert.AreEqual(25, Algorithms.CutRod(ps, ps.Length - 1));
            Assert.AreEqual(22, Algorithms.CutRod(ps, ps.Length - 2));
            Assert.AreEqual(18, Algorithms.CutRod(ps, ps.Length - 3));
        }
    }
}
