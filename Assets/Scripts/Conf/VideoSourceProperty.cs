using System;

[Serializable]
public class VideoSourceProperty
{
    public string name;
    public string type;
    public string description;
    public object value;

    public VideoSourceProperty(string name, string type, string description, object value)
    {
        this.name = name;
        this.type = type;
        this.description = description;
        this.value = value;
    }

    /// <summary>
    /// Get the typed value of the property
    /// </summary>
    /// <typeparam name="T">The type to cast to</typeparam>
    /// <returns>The typed value</returns>
    public T GetValue<T>()
    {
        try
        {
            if (value == null)
                return default(T);

            // Handle specific type conversions
            if (typeof(T) == typeof(float) && value is double)
            {
                return (T)(object)Convert.ToSingle(value);
            }

            if (typeof(T) == typeof(double) && value is float)
            {
                return (T)(object)Convert.ToDouble(value);
            }

            if (typeof(T) == typeof(string))
            {
                return (T)(object)value.ToString();
            }

            return (T)Convert.ChangeType(value, typeof(T));
        }
        catch (Exception e)
        {
            UnityEngine.Debug.LogError($"Failed to convert property '{name}' value '{value}' to type {typeof(T)}: {e.Message}");
            return default(T);
        }
    }

    /// <summary>
    /// Get the value as float (common use case)
    /// </summary>
    public float AsFloat()
    {
        return GetValue<float>();
    }

    /// <summary>
    /// Get the value as string
    /// </summary>
    public string AsString()
    {
        return GetValue<string>();
    }

    /// <summary>
    /// Get the value as int
    /// </summary>
    public int AsInt()
    {
        return GetValue<int>();
    }
}
