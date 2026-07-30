using System.Collections.Generic;

namespace Unity.XR.PICO.TOBSupport
{
    public class PoseInfo
    {
        public long timestamp;
        public double x;
        public double y;
        public double z;
        public double rw;
        public double rx;
        public double ry;
        public double rz;
        public int type;
        public int confidence;
        public int poseError;

        public List<long> reservedInt;
        public List<double> reservedDouble;

        public override string ToString()
        {
            return
                $"PoseInfo position=({x:F6}, {y:F6}, {z:F6}) rotation=({rx:F6}, {ry:F6}, {rz:F6}, {rw:F6})" +
                $" | timestamp={timestamp} | type={type} | confidence={confidence} | poseError={poseError}";
        }
    }
}
