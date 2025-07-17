using System;
using System.Collections.Generic;

namespace XRoboToolkit.Network
{
    /// <summary>
    /// Command handler interface for processing network data based on command type
    /// </summary>
    public interface ICommandHandler
    {
        /// <summary>
        /// Handles the command with the provided data
        /// </summary>
        /// <param name="data">The data payload</param>
        void HandleCommand(byte[] data);
    }

    /// <summary>
    /// Network data processor that routes commands to appropriate handlers
    /// </summary>
    public class NetworkDataProcessor
    {
        private readonly Dictionary<string, ICommandHandler> commandHandlers;

        public NetworkDataProcessor()
        {
            commandHandlers = new Dictionary<string, ICommandHandler>();
        }

        /// <summary>
        /// Registers a command handler for a specific command type
        /// </summary>
        /// <param name="command">The command string</param>
        /// <param name="handler">The handler implementation</param>
        public void RegisterCommandHandler(string command, ICommandHandler handler)
        {
            if (string.IsNullOrEmpty(command))
                throw new ArgumentException("Command cannot be null or empty", nameof(command));

            if (handler == null)
                throw new ArgumentNullException(nameof(handler));

            commandHandlers[command] = handler;
        }

        /// <summary>
        /// Unregisters a command handler
        /// </summary>
        /// <param name="command">The command string</param>
        /// <returns>True if handler was removed, false if not found</returns>
        public bool UnregisterCommandHandler(string command)
        {
            if (string.IsNullOrEmpty(command))
                return false;

            return commandHandlers.Remove(command);
        }

        /// <summary>
        /// Processes a network data protocol message
        /// </summary>
        /// <param name="protocol">The protocol message to process</param>
        /// <returns>True if command was handled, false if no handler found</returns>
        public bool ProcessCommand(NetworkDataProtocol protocol)
        {
            if (protocol == null)
                throw new ArgumentNullException(nameof(protocol));

            if (commandHandlers.TryGetValue(protocol.command, out ICommandHandler handler))
            {
                handler.HandleCommand(protocol.data);
                return true;
            }

            return false;
        }

        /// <summary>
        /// Processes a serialized network data protocol message
        /// </summary>
        /// <param name="serializedData">The serialized protocol message</param>
        /// <returns>True if command was handled, false if no handler found or deserialization failed</returns>
        public bool ProcessSerializedCommand(byte[] serializedData)
        {
            if (NetworkDataProtocolSerializer.TryDeserialize(serializedData, out NetworkDataProtocol protocol))
            {
                return ProcessCommand(protocol);
            }

            return false;
        }

        /// <summary>
        /// Gets all registered command types
        /// </summary>
        /// <returns>Array of registered command strings</returns>
        public string[] GetRegisteredCommands()
        {
            var commands = new string[commandHandlers.Count];
            commandHandlers.Keys.CopyTo(commands, 0);
            return commands;
        }

        /// <summary>
        /// Checks if a command handler is registered for the given command
        /// </summary>
        /// <param name="command">The command to check</param>
        /// <returns>True if handler exists, false otherwise</returns>
        public bool HasCommandHandler(string command)
        {
            return !string.IsNullOrEmpty(command) && commandHandlers.ContainsKey(command);
        }

        /// <summary>
        /// Clears all registered command handlers
        /// </summary>
        public void ClearAllHandlers()
        {
            commandHandlers.Clear();
        }
    }
}
