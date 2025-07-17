using System;

namespace Robot.V2.Network
{
   public enum Command
   {
      StartRobotCameraStream, // robot side
      StopRobotCameraStream, // robot side
   }

   public class TcpCommand
   {
      public static string GetString(Command command)
      {
         return Enum.GetName(typeof(Command), command);
      }

      public static Command GetCommand(string s)
      {
         return Enum.Parse<Command>(s);
      }
   }
}