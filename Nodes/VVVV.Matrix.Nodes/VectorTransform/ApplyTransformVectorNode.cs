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
    [PluginInfo(Name="ApplyTransform",Category="Transform", Version="Vector")]
    public class ApplyTransformVectorNode : IPluginEvaluate
    {
        [Input("Transform")]
        protected MatrixInput TransformIn;

        [Input("XYZ UnTransformed")]
        protected FastValueInput XYZIn;

        [Input("Threaded", IsSingle=true)]
        protected ISpread<bool> Threaded;

        [Input("XYZ Transformed")]
        protected ValueOutput XYZOut;

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
