using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using VVVV.DataTypes;
using VVVV.Hosting.IO.Pointers;
using VVVV.PluginInterfaces.V2;

namespace VVVV.Nodes
{
    [PluginInfo(Name = "Transform", Category = "2d", Version="")]
    public class Transform2dNode : IPluginEvaluate
    {
        [Input("Transform In")]
        protected MatrixInput TransformIn;

        [Input("Translate X")]
        protected FastValueInput TranslateX;

        [Input("Translate Y")]
        protected FastValueInput TranslateY;

        [Input("Scale X", DefaultValue=1)]
        protected FastValueInput ScaleX;

        [Input("Scale Y", DefaultValue = 1)]
        protected FastValueInput ScaleY;

        [Input("Rotate")]
        protected FastValueInput Rotate;

        [Input("Center X")]
        protected FastValueInput CenterX;

        [Input("Center Y")]
        protected FastValueInput CenterY;

        [Input("Threaded", IsSingle = true)]
        protected ISpread<bool> Threaded;

        [Input("Transform Out")]
        protected MatrixOutput TransformOut;

        public void Evaluate(int SpreadMax)
        {
            if (this.TransformIn.IsConnected)
            {

            }
            else
            {

            }
        }
    }
}
