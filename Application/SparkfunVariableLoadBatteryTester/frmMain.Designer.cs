namespace SparkfunVariableLoadBatteryTester
{
    partial class frmMain
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
      this.components = new System.ComponentModel.Container();
      System.Windows.Forms.DataVisualization.Charting.ChartArea chartArea1 = new System.Windows.Forms.DataVisualization.Charting.ChartArea();
      System.Windows.Forms.DataVisualization.Charting.ChartArea chartArea2 = new System.Windows.Forms.DataVisualization.Charting.ChartArea();
      System.Windows.Forms.DataVisualization.Charting.Legend legend1 = new System.Windows.Forms.DataVisualization.Charting.Legend();
      this.dataGridView = new System.Windows.Forms.DataGridView();
      this.chart = new System.Windows.Forms.DataVisualization.Charting.Chart();
      this.cboPorts = new System.Windows.Forms.ComboBox();
      this.btnConnect = new System.Windows.Forms.Button();
      this.btnStartTest = new System.Windows.Forms.Button();
      this.btnEndTest = new System.Windows.Forms.Button();
      this.numCurrentConst = new System.Windows.Forms.NumericUpDown();
      this.numVoltageMin = new System.Windows.Forms.NumericUpDown();
      this.lblStartTime = new System.Windows.Forms.Label();
      this.label2 = new System.Windows.Forms.Label();
      this.label3 = new System.Windows.Forms.Label();
      this.label4 = new System.Windows.Forms.Label();
      this.lblEndTime = new System.Windows.Forms.Label();
      this.label6 = new System.Windows.Forms.Label();
      this.txtOutput = new System.Windows.Forms.TextBox();
      this.btnBootload = new System.Windows.Forms.Button();
      this.batteryReadingBindingSource = new System.Windows.Forms.BindingSource(this.components);
      this.timeStampDataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
      this.iSourceDataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
      this.iLimitDataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
      this.vSourceDataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
      this.vMinDataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
      this.mAHoursDataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
      ((System.ComponentModel.ISupportInitialize)(this.dataGridView)).BeginInit();
      ((System.ComponentModel.ISupportInitialize)(this.chart)).BeginInit();
      ((System.ComponentModel.ISupportInitialize)(this.numCurrentConst)).BeginInit();
      ((System.ComponentModel.ISupportInitialize)(this.numVoltageMin)).BeginInit();
      ((System.ComponentModel.ISupportInitialize)(this.batteryReadingBindingSource)).BeginInit();
      this.SuspendLayout();
      // 
      // dataGridView
      // 
      this.dataGridView.AutoGenerateColumns = false;
      this.dataGridView.ColumnHeadersHeightSizeMode = System.Windows.Forms.DataGridViewColumnHeadersHeightSizeMode.AutoSize;
      this.dataGridView.Columns.AddRange(new System.Windows.Forms.DataGridViewColumn[] {
            this.timeStampDataGridViewTextBoxColumn,
            this.iSourceDataGridViewTextBoxColumn,
            this.iLimitDataGridViewTextBoxColumn,
            this.vSourceDataGridViewTextBoxColumn,
            this.vMinDataGridViewTextBoxColumn,
            this.mAHoursDataGridViewTextBoxColumn});
      this.dataGridView.DataSource = this.batteryReadingBindingSource;
      this.dataGridView.Location = new System.Drawing.Point(277, 382);
      this.dataGridView.Name = "dataGridView";
      this.dataGridView.Size = new System.Drawing.Size(955, 331);
      this.dataGridView.TabIndex = 0;
      // 
      // chart
      // 
      chartArea1.Name = "ChartArea1";
      chartArea2.Name = "ChartArea2";
      this.chart.ChartAreas.Add(chartArea1);
      this.chart.ChartAreas.Add(chartArea2);
      this.chart.DataSource = this.batteryReadingBindingSource;
      legend1.Name = "Legend1";
      this.chart.Legends.Add(legend1);
      this.chart.Location = new System.Drawing.Point(277, 12);
      this.chart.Name = "chart";
      this.chart.Size = new System.Drawing.Size(955, 364);
      this.chart.TabIndex = 1;
      this.chart.Text = "chart";
      // 
      // cboPorts
      // 
      this.cboPorts.FormattingEnabled = true;
      this.cboPorts.Location = new System.Drawing.Point(23, 12);
      this.cboPorts.Name = "cboPorts";
      this.cboPorts.Size = new System.Drawing.Size(121, 21);
      this.cboPorts.TabIndex = 2;
      this.cboPorts.Click += new System.EventHandler(this.cboPorts_Click);
      // 
      // btnConnect
      // 
      this.btnConnect.Location = new System.Drawing.Point(151, 9);
      this.btnConnect.Name = "btnConnect";
      this.btnConnect.Size = new System.Drawing.Size(75, 23);
      this.btnConnect.TabIndex = 3;
      this.btnConnect.Text = "Connect";
      this.btnConnect.UseVisualStyleBackColor = true;
      this.btnConnect.Click += new System.EventHandler(this.btnConnect_Click);
      // 
      // btnStartTest
      // 
      this.btnStartTest.Location = new System.Drawing.Point(23, 39);
      this.btnStartTest.Name = "btnStartTest";
      this.btnStartTest.Size = new System.Drawing.Size(65, 21);
      this.btnStartTest.TabIndex = 4;
      this.btnStartTest.Text = "Start Test";
      this.btnStartTest.UseVisualStyleBackColor = true;
      this.btnStartTest.Click += new System.EventHandler(this.btnStartTest_Click);
      // 
      // btnEndTest
      // 
      this.btnEndTest.Location = new System.Drawing.Point(94, 38);
      this.btnEndTest.Name = "btnEndTest";
      this.btnEndTest.Size = new System.Drawing.Size(64, 22);
      this.btnEndTest.TabIndex = 5;
      this.btnEndTest.Text = "End Test";
      this.btnEndTest.UseVisualStyleBackColor = true;
      this.btnEndTest.Click += new System.EventHandler(this.btnEndTest_Click);
      // 
      // numCurrentConst
      // 
      this.numCurrentConst.DecimalPlaces = 2;
      this.numCurrentConst.Location = new System.Drawing.Point(151, 96);
      this.numCurrentConst.Name = "numCurrentConst";
      this.numCurrentConst.Size = new System.Drawing.Size(120, 20);
      this.numCurrentConst.TabIndex = 6;
      this.numCurrentConst.Value = new decimal(new int[] {
            10,
            0,
            0,
            65536});
      // 
      // numVoltageMin
      // 
      this.numVoltageMin.DecimalPlaces = 2;
      this.numVoltageMin.Location = new System.Drawing.Point(151, 139);
      this.numVoltageMin.Name = "numVoltageMin";
      this.numVoltageMin.Size = new System.Drawing.Size(120, 20);
      this.numVoltageMin.TabIndex = 6;
      this.numVoltageMin.Value = new decimal(new int[] {
            30,
            0,
            0,
            65536});
      // 
      // lblStartTime
      // 
      this.lblStartTime.AutoSize = true;
      this.lblStartTime.Location = new System.Drawing.Point(111, 186);
      this.lblStartTime.Name = "lblStartTime";
      this.lblStartTime.Size = new System.Drawing.Size(27, 13);
      this.lblStartTime.TabIndex = 7;
      this.lblStartTime.Text = "N/A";
      // 
      // label2
      // 
      this.label2.AutoSize = true;
      this.label2.Location = new System.Drawing.Point(20, 98);
      this.label2.Name = "label2";
      this.label2.Size = new System.Drawing.Size(119, 13);
      this.label2.TabIndex = 8;
      this.label2.Text = "Constant Current Value:";
      // 
      // label3
      // 
      this.label3.AutoSize = true;
      this.label3.Location = new System.Drawing.Point(20, 141);
      this.label3.Name = "label3";
      this.label3.Size = new System.Drawing.Size(126, 13);
      this.label3.TabIndex = 9;
      this.label3.Text = "Minimum Battery Voltage:";
      // 
      // label4
      // 
      this.label4.AutoSize = true;
      this.label4.Location = new System.Drawing.Point(20, 186);
      this.label4.Name = "label4";
      this.label4.Size = new System.Drawing.Size(82, 13);
      this.label4.TabIndex = 7;
      this.label4.Text = "Test Start Time:";
      // 
      // lblEndTime
      // 
      this.lblEndTime.AutoSize = true;
      this.lblEndTime.Location = new System.Drawing.Point(111, 207);
      this.lblEndTime.Name = "lblEndTime";
      this.lblEndTime.Size = new System.Drawing.Size(27, 13);
      this.lblEndTime.TabIndex = 7;
      this.lblEndTime.Text = "N/A";
      // 
      // label6
      // 
      this.label6.AutoSize = true;
      this.label6.Location = new System.Drawing.Point(20, 208);
      this.label6.Name = "label6";
      this.label6.Size = new System.Drawing.Size(79, 13);
      this.label6.TabIndex = 7;
      this.label6.Text = "Test End Time:";
      // 
      // txtOutput
      // 
      this.txtOutput.Location = new System.Drawing.Point(13, 257);
      this.txtOutput.Multiline = true;
      this.txtOutput.Name = "txtOutput";
      this.txtOutput.Size = new System.Drawing.Size(258, 143);
      this.txtOutput.TabIndex = 10;
      // 
      // btnBootload
      // 
      this.btnBootload.Location = new System.Drawing.Point(165, 38);
      this.btnBootload.Name = "btnBootload";
      this.btnBootload.Size = new System.Drawing.Size(75, 23);
      this.btnBootload.TabIndex = 11;
      this.btnBootload.Text = "Bootload";
      this.btnBootload.UseVisualStyleBackColor = true;
      this.btnBootload.Click += new System.EventHandler(this.btnBootload_Click);
      // 
      // batteryReadingBindingSource
      // 
      this.batteryReadingBindingSource.DataSource = typeof(SparkfunVariableLoadBatteryTester.BatteryReading);
      // 
      // timeStampDataGridViewTextBoxColumn
      // 
      this.timeStampDataGridViewTextBoxColumn.DataPropertyName = "TimeStamp";
      this.timeStampDataGridViewTextBoxColumn.HeaderText = "TimeStamp";
      this.timeStampDataGridViewTextBoxColumn.Name = "timeStampDataGridViewTextBoxColumn";
      // 
      // iSourceDataGridViewTextBoxColumn
      // 
      this.iSourceDataGridViewTextBoxColumn.DataPropertyName = "I_Source";
      this.iSourceDataGridViewTextBoxColumn.HeaderText = "I_Source";
      this.iSourceDataGridViewTextBoxColumn.Name = "iSourceDataGridViewTextBoxColumn";
      // 
      // iLimitDataGridViewTextBoxColumn
      // 
      this.iLimitDataGridViewTextBoxColumn.DataPropertyName = "I_Limit";
      this.iLimitDataGridViewTextBoxColumn.HeaderText = "I_Limit";
      this.iLimitDataGridViewTextBoxColumn.Name = "iLimitDataGridViewTextBoxColumn";
      // 
      // vSourceDataGridViewTextBoxColumn
      // 
      this.vSourceDataGridViewTextBoxColumn.DataPropertyName = "V_Source";
      this.vSourceDataGridViewTextBoxColumn.HeaderText = "V_Source";
      this.vSourceDataGridViewTextBoxColumn.Name = "vSourceDataGridViewTextBoxColumn";
      // 
      // vMinDataGridViewTextBoxColumn
      // 
      this.vMinDataGridViewTextBoxColumn.DataPropertyName = "V_Min";
      this.vMinDataGridViewTextBoxColumn.HeaderText = "V_Min";
      this.vMinDataGridViewTextBoxColumn.Name = "vMinDataGridViewTextBoxColumn";
      // 
      // mAHoursDataGridViewTextBoxColumn
      // 
      this.mAHoursDataGridViewTextBoxColumn.DataPropertyName = "mA_Hours";
      this.mAHoursDataGridViewTextBoxColumn.HeaderText = "mA_Hours";
      this.mAHoursDataGridViewTextBoxColumn.Name = "mAHoursDataGridViewTextBoxColumn";
      // 
      // frmMain
      // 
      this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
      this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
      this.ClientSize = new System.Drawing.Size(1244, 725);
      this.Controls.Add(this.btnBootload);
      this.Controls.Add(this.txtOutput);
      this.Controls.Add(this.label3);
      this.Controls.Add(this.label2);
      this.Controls.Add(this.label6);
      this.Controls.Add(this.label4);
      this.Controls.Add(this.lblEndTime);
      this.Controls.Add(this.lblStartTime);
      this.Controls.Add(this.numVoltageMin);
      this.Controls.Add(this.numCurrentConst);
      this.Controls.Add(this.btnEndTest);
      this.Controls.Add(this.btnStartTest);
      this.Controls.Add(this.btnConnect);
      this.Controls.Add(this.cboPorts);
      this.Controls.Add(this.chart);
      this.Controls.Add(this.dataGridView);
      this.Name = "frmMain";
      this.Text = "Form1";
      this.Load += new System.EventHandler(this.frmMain_Load);
      ((System.ComponentModel.ISupportInitialize)(this.dataGridView)).EndInit();
      ((System.ComponentModel.ISupportInitialize)(this.chart)).EndInit();
      ((System.ComponentModel.ISupportInitialize)(this.numCurrentConst)).EndInit();
      ((System.ComponentModel.ISupportInitialize)(this.numVoltageMin)).EndInit();
      ((System.ComponentModel.ISupportInitialize)(this.batteryReadingBindingSource)).EndInit();
      this.ResumeLayout(false);
      this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.DataGridView dataGridView;
        private System.Windows.Forms.DataVisualization.Charting.Chart chart;
        private System.Windows.Forms.ComboBox cboPorts;
        private System.Windows.Forms.Button btnConnect;
        private System.Windows.Forms.Button btnStartTest;
        private System.Windows.Forms.Button btnEndTest;
        private System.Windows.Forms.NumericUpDown numCurrentConst;
        private System.Windows.Forms.NumericUpDown numVoltageMin;
        private System.Windows.Forms.Label lblStartTime;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Label lblEndTime;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.DataGridViewTextBoxColumn timeStampDataGridViewTextBoxColumn;
        private System.Windows.Forms.DataGridViewTextBoxColumn iSourceDataGridViewTextBoxColumn;
        private System.Windows.Forms.DataGridViewTextBoxColumn iLimitDataGridViewTextBoxColumn;
        private System.Windows.Forms.DataGridViewTextBoxColumn vSourceDataGridViewTextBoxColumn;
        private System.Windows.Forms.DataGridViewTextBoxColumn vMinDataGridViewTextBoxColumn;
        private System.Windows.Forms.DataGridViewTextBoxColumn mAHoursDataGridViewTextBoxColumn;
        private System.Windows.Forms.BindingSource batteryReadingBindingSource;
        private System.Windows.Forms.TextBox txtOutput;
    private System.Windows.Forms.Button btnBootload;
  }
}

