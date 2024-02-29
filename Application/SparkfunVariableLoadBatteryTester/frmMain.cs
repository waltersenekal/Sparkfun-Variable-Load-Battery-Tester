using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO.Ports;
using System.Threading;
using Gurux.Serial;
using System.Windows.Forms.DataVisualization.Charting;
using System.Diagnostics;

namespace SparkfunVariableLoadBatteryTester
{  
  public partial class frmMain : Form
  {
    int baudRate = 115200;
    int dataBits = 8;
    Parity parity = Parity.None;
    StopBits stopBits = StopBits.One;
    Gurux.Serial.GXSerial serialPort = new GXSerial();
    Handshake serialHandshake = Handshake.None;
    string[] Last_Entry_Name = new string[10];
    Double[] Last_Entry_Value = new Double[10];
    List<DateTime> T_TimestampList = new List<DateTime>();
    List<Double> I_SourceList = new List<Double>();
    List<Double> I_LimitList = new List<Double>();
    List<Double> V_SourceList = new List<Double>();
    List<Double> V_MinList = new List<Double>();
    List<Double> mA_HoursList = new List<Double>();
    DateTime T_Timestamp_last = DateTime.Now;
    Double I_Source_last = 0;
    Double I_Limit_last = 0;
    Double V_Source_last = 0;
    Double V_Min_last = 0;
    Double mA_Hours_last = 0;
    DateTime T_Timestamp_prev = DateTime.Now;
    Double I_Source_prev = 0;
    Double I_Limit_prev = 0;
    Double V_Source_prev = 0;
    Double V_Min_prev = 0;
    Double mA_Hours_prev = 0;
    Double Counter = 0;
    string filePath;
    string CSV_Seperator = ",";

    public frmMain()
    {
      InitializeComponent();
      serialPort.OnReceived += GxSerial_OnReceived;
      serialPort.BaudRate = baudRate;
      serialPort.DataBits = dataBits;
      serialPort.Parity = parity;
      serialPort.StopBits = stopBits;


      PopulateAvailableSerialPorts();
      generateChart();
      filePath = Application.StartupPath + "\\report"  + "_" + DateTime.Now.ToString("yyyyMMdd_HHmmss") + ".csv";
      String Message = "T_Timestamp" + CSV_Seperator + "I_Source" + CSV_Seperator + "I_Limit" + CSV_Seperator + "V_Source" + CSV_Seperator + "V_Min" + CSV_Seperator + "mA_Hours" + "\r\n";
      WriteToFile(Message);

    }
    private void PopulateAvailableSerialPorts()
    {
      string[] ports = SerialPort.GetPortNames();
      if (ports.Length > 0)
      {
        cboPorts.Items.Clear();
        foreach (string port in ports)
        {
          cboPorts.Items.Add(port);
        }
      }
    }
   private void WriteToFile(string Message)
    {
      if (InvokeRequired)
      {
        Action safeCall = delegate { WriteToFile(Message); };
        Invoke(safeCall);
      }
      else
      {
        try
        {
          System.IO.File.AppendAllText(filePath, Message);
        }
        catch (Exception ex)
        {

          MessageBox.Show(ex.Message);
        }
        
      }
      
    }

    private void generateChart()
    {
      Random random = new Random();
      //var objChart = chart.ChartAreas[0];
      //objChart.AxisX.IntervalType = System.Windows.Forms.DataVisualization.Charting.DateTimeIntervalType.Auto;
      //objChart.AxisX.Minimum = 0;
      //objChart.AxisX.Maximum = 12;
      //objChart.AxisY.IntervalType = System.Windows.Forms.DataVisualization.Charting.DateTimeIntervalType.Auto;
      
      Series I_Source_Series = new Series();
      Series I_Limit_Series= new Series();
      Series V_Source_Series = new Series();
      Series V_Min_Series = new Series();
      Series mA_Hours_Series = new Series();
      I_Source_Series.Name = "I_Source";
      //I_Source_Series.Legend = "I_Source";
      //I_Source_Series.ChartArea = "I_Source";
      I_Source_Series.ChartType = System.Windows.Forms.DataVisualization.Charting.SeriesChartType.Line;
      I_Source_Series.Color = Color.FromArgb(random.Next(256), random.Next(256), random.Next(256));

      I_Limit_Series.Name = "I_Limit";
      //I_Limit_Series.Legend = "I_Limit";
      //I_Limit_Series.ChartArea = "I_Limit";
      I_Limit_Series.ChartType = System.Windows.Forms.DataVisualization.Charting.SeriesChartType.Line;
      I_Limit_Series.Color = Color.FromArgb(random.Next(256), random.Next(256), random.Next(256));

      V_Source_Series.Name = "V_Source";
      //V_Source_Series.Legend = "V_Source";
      //V_Source_Series.ChartArea = "V_Source";
      V_Source_Series.ChartType = System.Windows.Forms.DataVisualization.Charting.SeriesChartType.Line;
      V_Source_Series.Color = Color.FromArgb(random.Next(256), random.Next(256), random.Next(256));

      V_Min_Series.Name = "V_Min";
      //V_Min_Series.Legend = "V_Min";
      //V_Min_Series.ChartArea = "V_Min";
      V_Min_Series.ChartType = System.Windows.Forms.DataVisualization.Charting.SeriesChartType.Line;
      V_Min_Series.Color = Color.FromArgb(random.Next(256), random.Next(256), random.Next(256));

      mA_Hours_Series.Name = "mA_Hours";
      //mA_Hours_Series.Legend = "mA_Hours";
      //mA_Hours_Series.ChartArea = "mA_Hours";
      mA_Hours_Series.ChartType = System.Windows.Forms.DataVisualization.Charting.SeriesChartType.Line;
      mA_Hours_Series.Color = Color.FromArgb(random.Next(256), random.Next(256), random.Next(256));



      chart.Series.Clear();
      chart.Series.Add(I_Source_Series);
      chart.Series.Add(I_Limit_Series);
      chart.Series.Add(V_Source_Series);
      chart.Series.Add(V_Min_Series);
      chart.Series.Add(mA_Hours_Series);
    }

    private void btnConnect_Click(object sender, EventArgs e)
    {
      txtOutput.Text = string.Empty;
      OpenComPort();
    }

    private void btnStartTest_Click(object sender, EventArgs e)
    {
      T_TimestampList.Clear();
      I_SourceList.Clear();
      I_LimitList.Clear();
      V_SourceList.Clear();
      V_MinList.Clear();
      mA_HoursList.Clear();
      lblStartTime.Text = "N/A";
      lblEndTime.Text = "N/A";
      serialPort.Send("I" + numCurrentConst.Value + "\n");
      Thread.Sleep(1000);
      serialPort.Send("V" + numVoltageMin.Value + "\n");
      Thread.Sleep(1000);
      serialPort.Send("E0\n");
      Thread.Sleep(1000);
      serialPort.Send("R\n");
      Thread.Sleep(1000);
      serialPort.Send("E1\n");
      Thread.Sleep(1000);
    }

    private void btnEndTest_Click(object sender, EventArgs e)
    {
      serialPort.Send("E0\n");
    }

    private void btnBootload_Click(object sender, EventArgs e)
    {
      if (serialPort.IsOpen)
      {
        serialPort.Send("B\n");
      }
      //serialPort.Close();
      frmBootload frm = new frmBootload();
      frm.ShowDialog();
    }

    private void OpenComPort()
    {
      if (serialPort.IsOpen)
      {
        serialPort.Close();
      }
      serialPort.PortName = cboPorts.Text;
      serialPort.Open();
    }

    private void GxSerial_OnReceived(object sender, Gurux.Common.ReceiveEventArgs e)
    {
      byte[] myData = (byte[])e.Data;
      string resp = DecodeVt100(myData);
      ClearSerialData();
      WriteSerialData(resp + "\r\n");
      ProcessData();
    }

    string DecodeVt100(byte[] data)
    {
      List<byte[]> dataList = new List<byte[]>();
      byte[] pattern1 = new byte[] { 0x1B, 0x5B, 0x32, 0x4a };
      byte[] pattern2 = new byte[] { 0x1B, 0x5B };
      byte[] pattern3 = new byte[] { 0x1B };
      byte[] pattern4 = new byte[] { 0x31, 0x66 };
      byte[] pattern5 = new byte[] { 0x31, 0x32, 0x66 };
      byte[] pattern6 = new byte[] { 0x3B };
      byte[] pattern7 = new byte[] { 0x5B };

      // Initialize the StringBuilder for the decoded string
      StringBuilder decodedStrBuilder = new StringBuilder();
      data = RemoveBytes(data, pattern1);
      data = ReplaceBytes(data, pattern2, pattern3);
      data = RemoveBytes(data, pattern4);
      data = RemoveBytes(data, pattern5);
      data = RemoveBytes(data, pattern7);
      dataList = SplitByteArray(data, pattern3[0]);
      foreach (byte[] b in dataList)
      {
        //Only use lines that contains ';'
        if (FindBytes(b, pattern6) > 0)
        {
          List<byte[]> entry = SplitByteArray(b, pattern6[0]);
          if (entry.Count == 2)
          {
            string each_number = System.Text.Encoding.UTF8.GetString(entry[0]);
            int each_number_i = Int32.Parse(each_number);
            string each_data = System.Text.Encoding.UTF8.GetString(entry[1]);
            if (each_data.Contains(':'))
            {
              //This is the Entry Name
              each_data = each_data.Replace(':', ' ');
              each_data = each_data.Trim();
              Last_Entry_Name[each_number_i] = each_data;
            }
            else
            {
              //This is the Entry Value
              each_data = each_data.Trim();
              Last_Entry_Value[each_number_i] = Convert.ToDouble(each_data, System.Globalization.CultureInfo.InvariantCulture);
            }
          }
        }
      }
      T_Timestamp_prev = T_Timestamp_last;
      I_Source_prev = I_Source_last;
      I_Limit_prev = I_Limit_last;
      V_Source_prev = V_Source_last;
      V_Min_prev = V_Min_last;
      mA_Hours_prev = mA_Hours_last;
      T_Timestamp_last = DateTime.Now;
      I_Source_last = Math.Round(Last_Entry_Value[1],2);
      I_Limit_last = Math.Round(Last_Entry_Value[2],2);
      V_Source_last = Math.Round(Last_Entry_Value[3],2);
      V_Min_last = Math.Round(Last_Entry_Value[4],2);
      mA_Hours_last = Math.Round(Last_Entry_Value[5],2);
      T_TimestampList.Add(DateTime.Now);
      I_SourceList.Add(I_Source_last);
      I_LimitList.Add(I_Limit_last);
      V_SourceList.Add(V_Source_last);
      V_MinList.Add(V_Min_last);
      mA_HoursList.Add(mA_Hours_last);
      return LastValuesToString();
    }
    private byte[] RemoveBytes(byte[] input, byte[] pattern)
    {
      if ((pattern.Length == 0) || (input == null)) return input;
      var result = new List<byte>();
      int i;
      for (i = 0; i <= input.Length - pattern.Length; i++)
      {
        var foundMatch = !pattern.Where((t, j) => input[i + j] != t).Any();
        if (foundMatch) i += pattern.Length - 1;
        else result.Add(input[i]);
      }
      for (; i < input.Length; i++)
      {
        result.Add(input[i]);
      }
      return result.ToArray();
    }
    public int FindBytes(byte[] src, byte[] find)
    {
      int index = -1;
      int matchIndex = 0;
      // handle the complete source array
      for (int i = 0; i < src.Length; i++)
      {
        if (src[i] == find[matchIndex])
        {
          if (matchIndex == (find.Length - 1))
          {
            index = i - matchIndex;
            break;
          }
          matchIndex++;
        }
        else if (src[i] == find[0])
        {
          matchIndex = 1;
        }
        else
        {
          matchIndex = 0;
        }

      }
      return index;
    }

    private byte[] ReplaceBytes(byte[] src, byte[] search, byte[] repl)
    {
      int index = 0;
      byte[] dst = null;
      do
      {
        index = FindBytes(src, search);
        if (index >= 0)
        {
          dst = new byte[src.Length - search.Length + repl.Length];
          // before found array
          Buffer.BlockCopy(src, 0, dst, 0, index);
          // repl copy
          Buffer.BlockCopy(repl, 0, dst, index, repl.Length);
          // rest of src array
          Buffer.BlockCopy(
              src,
              index + search.Length,
              dst,
              index + repl.Length,
              src.Length - (index + search.Length));
        }
        src = dst;
      } while (index > 0);


      return dst;
    }
    private List<byte[]> SplitByteArray(byte[] data, byte split)
    {
      List<byte[]> result = new List<byte[]>();
      if (data != null)
      {
        int start = 0;
        for (int i = 0; i < data.Length; i++)
        {
          if (data[i] == split && i != 0)
          {
            byte[] _in = new byte[i - start];
            Array.Copy(data, start, _in, 0, i - start);
            result.Add(_in);
            start = i + 1;
          }
          else if (data[i] == split && i == 0)
          {
            start = i + 1;
          }
          else if (data.Length - 1 == i && i != start)
          {
            byte[] _in = new byte[i - start + 1];
            Array.Copy(data, start, _in, 0, i - start + 1);
            result.Add(_in);
          }
        }
      }
      return result;
    }
    string LastValuesToString()
    {
      string Response = "";
      for (int i = 0; i < Last_Entry_Name.Length; i++)
      {
        if (Last_Entry_Name[i] != null)
        {
          Response += Last_Entry_Name[i] + ": " + Math.Round(Last_Entry_Value[i],2) + "\r\n";
        }
      }
      return Response;
    }

    private void ClearSerialData()
    {
      if (txtOutput.InvokeRequired)
      {
        Action safeClear = delegate { ClearSerialData(); };
        txtOutput.Invoke(safeClear);
      }
      else
      {
        txtOutput.Text = "";
      }
    }

    private void WriteSerialData(string data)
    {
      if (txtOutput.InvokeRequired)
      {
        Action safeWrite = delegate { WriteSerialData(data); };
        txtOutput.Invoke(safeWrite);
      }
      else
      {
        txtOutput.Text += data;
      }
    }
    private void WriteConsole(char c)
    {
      string response = c.ToString();
      WriteSerialData(response);
    }

    private void WriteConsole(string s)
    {
      string response = s;
      WriteSerialData(response);
    }

    private void writeStartLabel(string message)
    {
      if (lblStartTime.InvokeRequired)
      {
        Action safeWrite = delegate { writeStartLabel(message); };
        lblStartTime.Invoke(safeWrite);
      }
      else
      {
        lblStartTime.Text = message;
      }
    }

    private void writeEndLabel(string message)
    {
      if (lblEndTime.InvokeRequired)
      {
        Action safeWrite = delegate { writeEndLabel(message); };
        lblEndTime.Invoke(safeWrite);
      }
      else
      {
        lblEndTime.Text = message;
      }
    }

    private void ProcessData()
    {
      //if ISource prev=0 and last >0 then Just Started
      if (I_Source_prev == 0 && I_Source_last > 0)
      {
        T_TimestampList.Clear();
        I_SourceList.Clear();
        I_LimitList.Clear();
        V_SourceList.Clear();
        V_MinList.Clear();
        mA_HoursList.Clear();
        writeStartLabel(DateTime.Now.ToString("yyyy/MM/dd HH:mm:ss"));
        writeEndLabel("N/A");
      }
      //if ISource prev>0 and last =0 then Just Stopped
      if (I_Source_prev > 0 && I_Source_last == 0)
      {
        writeEndLabel(DateTime.Now.ToString("yyyy/MM/dd HH:mm:ss"));
      }
      BatteryReading ReadingEntry = new BatteryReading();
      ReadingEntry.TimeStamp = T_Timestamp_last;
      ReadingEntry.I_Source = I_Source_last;
      ReadingEntry.I_Limit = I_Limit_last;
      ReadingEntry.V_Source = V_Source_last;
      ReadingEntry.V_Min = V_Min_last;
      ReadingEntry.mA_Hours = mA_Hours_last;
      AddDataEntry(ReadingEntry);
    }
    private void AddDataEntry(BatteryReading ReadingEntry)
    {
      if (InvokeRequired)
      {
        Action safeCall = delegate { AddDataEntry(ReadingEntry); };
        Invoke(safeCall);
      }
      else
      {
        batteryReadingBindingSource.Add(ReadingEntry);
        UpdateChart(ReadingEntry);
        WriteEntryToFile(ReadingEntry);
      }
    }
    private void WriteEntryToFile(BatteryReading ReadingEntry)
    {
      String Message = ReadingEntry.TimeStamp + CSV_Seperator + ReadingEntry.I_Source + CSV_Seperator + ReadingEntry.I_Limit + CSV_Seperator + ReadingEntry.V_Source + CSV_Seperator + ReadingEntry.V_Min + CSV_Seperator + ReadingEntry.mA_Hours + "\r\n";
      WriteToFile(Message);
    }
    private void UpdateChart(BatteryReading ReadingEntry)
    {
      double XAxis = ReadingEntry.TimeStamp.Ticks;
      XAxis = Counter++;
      chart.Series["I_Source"].Points.AddXY(XAxis, ReadingEntry.I_Source);
      
      chart.Series["I_Limit"].Points.AddXY(XAxis, ReadingEntry.I_Limit);

      chart.Series["V_Source"].Points.AddXY(XAxis, ReadingEntry.V_Source);

      chart.Series["V_Min"].Points.AddXY(XAxis, ReadingEntry.V_Min);

      //chart.Series["mA_Hours"].Points.AddXY(ReadingEntry.TimeStamp, ReadingEntry.mA_Hours);
      chart.Refresh();
    }

    private void frmMain_Load(object sender, EventArgs e)
        {
          batteryReadingBindingSource.DataSource = new List<BatteryReading>();
        }

    private void cboPorts_Click(object sender, EventArgs e)
    {
      PopulateAvailableSerialPorts();
    }
  }
}
