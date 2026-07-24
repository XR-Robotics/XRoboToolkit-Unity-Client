using System;

public static class MicrophoneCapturePlan
{
    public static int ChunkFrames(int sampleRate, int frameDurationMs)
    {
        return Math.Max(1, sampleRate * frameDurationMs / 1000);
    }

    public static int AvailableFrames(int currentPosition, int capturePosition, int clipFrames)
    {
        if (clipFrames <= 0 || currentPosition < 0 || currentPosition >= clipFrames)
        {
            return 0;
        }

        return currentPosition >= capturePosition
            ? currentPosition - capturePosition
            : clipFrames - capturePosition + currentPosition;
    }

    public static int BacklogSkipFrames(int availableFrames, int maxBacklogFrames)
    {
        return Math.Max(0, availableFrames - Math.Max(1, maxBacklogFrames));
    }

    public static int ConsumableFrames(int availableFrames, int chunkFrames)
    {
        int safeChunkFrames = Math.Max(1, chunkFrames);
        return Math.Max(0, availableFrames) / safeChunkFrames * safeChunkFrames;
    }
}
