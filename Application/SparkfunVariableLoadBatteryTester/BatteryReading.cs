using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace SparkfunVariableLoadBatteryTester
{
  public class BatteryReading
  {
    public DateTime TimeStamp { get; set; }

    public Double I_Source { get; set; }

    public Double I_Limit { get; set; }

    public Double V_Source { get; set; }

    public Double V_Min { get; set; }

    public Double mA_Hours { get; set; }

    public BatteryReading() { }

    public object this[string propertyname]
    {
      get { return this.GetType().GetProperty(propertyname).GetValue(this, null); }
      set { this.GetType().GetProperty(propertyname).SetValue(this, value, null); }
    }
  }
}
