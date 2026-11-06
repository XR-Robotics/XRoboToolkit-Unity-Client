using NUnit.Framework;
using System.Collections.Generic;

namespace ByteDance.PICO.IconConfigurator.Editor.Tests
{
    public class ManualLayerStateTests
    {
        [Test]
        public void Constructor_WhenCreated_UsesTwoLayersByDefault()
        {
            ManualLayerState state = new ManualLayerState();

            Assert.That(state.Layers, Has.Count.EqualTo(2));
        }

        [Test]
        public void AddEmptyLayer_WhenDefaultState_AddsThirdLayer()
        {
            ManualLayerState state = new ManualLayerState();

            state.AddEmptyLayer();

            Assert.That(state.Layers, Has.Count.EqualTo(3));
        }

        [Test]
        public void AddEmptyLayer_WhenAlreadyAtMaximum_DoesNotAppendFourthLayer()
        {
            ManualLayerState state = new ManualLayerState();

            state.AddEmptyLayer();
            state.AddEmptyLayer();

            Assert.That(state.Layers, Has.Count.EqualTo(3));
        }

        [Test]
        public void LayersSetter_WhenGivenFourLayers_TrimsToThreeLayers()
        {
            ManualLayerState state = new ManualLayerState
            {
                Layers = new List<IconLayerConfig>
                {
                    new IconLayerConfig { LayerKind = IconLayerKind.Background },
                    new IconLayerConfig { LayerKind = IconLayerKind.Foreground1 },
                    new IconLayerConfig { LayerKind = IconLayerKind.Foreground2 },
                    new IconLayerConfig { LayerKind = IconLayerKind.Foreground2 },
                },
            };

            Assert.That(state.Layers, Has.Count.EqualTo(3));
        }
    }
}
