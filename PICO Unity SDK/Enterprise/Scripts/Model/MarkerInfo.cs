namespace ByteDance.PICO.Enterprise
{
    public class MarkerInfo
    {
        // position
        public double posX;
        public double posY;
        public double posZ;

        // rotation
        public double rotationX;
        public double rotationY;
        public double rotationZ;
        public double rotationW;

        // Flag bit: invalid recognition=0, valid recognition=1
        public int validFlag;

        // Type: static=1 / dynamic=0
        public int markerType;

        // marker id
        public int iMarkerId;

        // Timestamp of detected image
        public double dTimestamp;

        // Reserved flag bits
        public float[] reserve;

        public override string ToString()
        {
            return $"{nameof(posX)}: {posX}, {nameof(posY)}: {posY}, {nameof(posZ)}: {posZ}, {nameof(rotationX)}: {rotationX}, {nameof(rotationY)}: {rotationY}, {nameof(rotationZ)}: {rotationZ}, {nameof(rotationW)}: {rotationW}, {nameof(validFlag)}: {validFlag}, {nameof(markerType)}: {markerType}, {nameof(iMarkerId)}: {iMarkerId}, {nameof(dTimestamp)}: {dTimestamp}, {nameof(reserve)}: {string.Join(" ", reserve)}";
        }
    }
}