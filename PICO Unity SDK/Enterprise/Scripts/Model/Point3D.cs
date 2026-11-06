namespace ByteDance.PICO.Enterprise
{
    public class Point3D
    {
        public double x;
        public double y;
        public double z;

        public Point3D()
        {
        }

        public override string ToString()
        {
            return $"Point3D:{nameof(x)}: {x}, {nameof(y)}: {y}, {nameof(z)}: {z}";
        }
    }
}