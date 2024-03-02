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
      Syncfusion.Windows.Forms.Chart.ChartSeries chartSeries1 = new Syncfusion.Windows.Forms.Chart.ChartSeries();
      Syncfusion.Windows.Forms.Chart.ChartDataBindModel chartDataBindModel1 = new Syncfusion.Windows.Forms.Chart.ChartDataBindModel();
      Syncfusion.Windows.Forms.Chart.ChartCustomShapeInfo chartCustomShapeInfo1 = new Syncfusion.Windows.Forms.Chart.ChartCustomShapeInfo();
      Syncfusion.Windows.Forms.Chart.ChartLineInfo chartLineInfo1 = new Syncfusion.Windows.Forms.Chart.ChartLineInfo();
      Syncfusion.Windows.Forms.Chart.ChartToolBarSaveItem chartToolBarSaveItem1 = new Syncfusion.Windows.Forms.Chart.ChartToolBarSaveItem();
      Syncfusion.Windows.Forms.Chart.ChartToolBarCopyItem chartToolBarCopyItem1 = new Syncfusion.Windows.Forms.Chart.ChartToolBarCopyItem();
      Syncfusion.Windows.Forms.Chart.ChartToolBarPrintItem chartToolBarPrintItem1 = new Syncfusion.Windows.Forms.Chart.ChartToolBarPrintItem();
      Syncfusion.Windows.Forms.Chart.ChartToolBarPrintPreviewItem chartToolBarPrintPreviewItem1 = new Syncfusion.Windows.Forms.Chart.ChartToolBarPrintPreviewItem();
      Syncfusion.Windows.Forms.Chart.ChartToolBarSplitter chartToolBarSplitter1 = new Syncfusion.Windows.Forms.Chart.ChartToolBarSplitter();
      Syncfusion.Windows.Forms.Chart.ChartToolBarPaletteItem chartToolBarPaletteItem1 = new Syncfusion.Windows.Forms.Chart.ChartToolBarPaletteItem();
      Syncfusion.Windows.Forms.Chart.ChartToolBarStyleItem chartToolBarStyleItem1 = new Syncfusion.Windows.Forms.Chart.ChartToolBarStyleItem();
      Syncfusion.Windows.Forms.Chart.ChartToolBarTypeItem chartToolBarTypeItem1 = new Syncfusion.Windows.Forms.Chart.ChartToolBarTypeItem();
      Syncfusion.Windows.Forms.Chart.ChartToolBarSeries3DItem chartToolBarSeries3DItem1 = new Syncfusion.Windows.Forms.Chart.ChartToolBarSeries3DItem();
      Syncfusion.Windows.Forms.Chart.ChartToolBarShowLegendItem chartToolBarShowLegendItem1 = new Syncfusion.Windows.Forms.Chart.ChartToolBarShowLegendItem();
      this.dataGridView = new System.Windows.Forms.DataGridView();
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
      this.chartVoltage = new Syncfusion.Windows.Forms.Chart.ChartControl();
      this.button1 = new System.Windows.Forms.Button();
      this.btnTestClear = new System.Windows.Forms.Button();
      this.btnTestAdd = new System.Windows.Forms.Button();
      this.numBatMaxVoltage = new System.Windows.Forms.NumericUpDown();
      this.numBatCapacity = new System.Windows.Forms.NumericUpDown();
      this.label1 = new System.Windows.Forms.Label();
      this.label5 = new System.Windows.Forms.Label();
      this.batteryReadingBindingSource = new System.Windows.Forms.BindingSource(this.components);
      this.timeStampDataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
      this.iSourceDataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
      this.iLimitDataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
      this.vSourceDataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
      this.vMinDataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
      this.mAHoursDataGridViewTextBoxColumn = new System.Windows.Forms.DataGridViewTextBoxColumn();
      this.b_TestisRunning = new System.Windows.Forms.DataGridViewCheckBoxColumn();
      ((System.ComponentModel.ISupportInitialize)(this.dataGridView)).BeginInit();
      ((System.ComponentModel.ISupportInitialize)(this.numCurrentConst)).BeginInit();
      ((System.ComponentModel.ISupportInitialize)(this.numVoltageMin)).BeginInit();
      ((System.ComponentModel.ISupportInitialize)(this.numBatMaxVoltage)).BeginInit();
      ((System.ComponentModel.ISupportInitialize)(this.numBatCapacity)).BeginInit();
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
            this.mAHoursDataGridViewTextBoxColumn,
            this.b_TestisRunning});
      this.dataGridView.DataSource = this.batteryReadingBindingSource;
      this.dataGridView.Location = new System.Drawing.Point(277, 382);
      this.dataGridView.Name = "dataGridView";
      this.dataGridView.Size = new System.Drawing.Size(955, 331);
      this.dataGridView.TabIndex = 0;
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
      this.numCurrentConst.Location = new System.Drawing.Point(150, 131);
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
      this.numVoltageMin.Location = new System.Drawing.Point(151, 160);
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
      this.label2.Location = new System.Drawing.Point(19, 133);
      this.label2.Name = "label2";
      this.label2.Size = new System.Drawing.Size(119, 13);
      this.label2.TabIndex = 8;
      this.label2.Text = "Constant Current Value:";
      // 
      // label3
      // 
      this.label3.AutoSize = true;
      this.label3.Location = new System.Drawing.Point(20, 162);
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
      // chartVoltage
      // 
      this.chartVoltage.BackInterior = new Syncfusion.Drawing.BrushInfo(Syncfusion.Drawing.GradientStyle.Vertical, new System.Drawing.Color[] {
            System.Drawing.Color.FromArgb(((int)(((byte)(0)))), ((int)(((byte)(0)))), ((int)(((byte)(0))))),
            System.Drawing.Color.FromArgb(((int)(((byte)(208)))), ((int)(((byte)(208)))), ((int)(((byte)(208))))),
            System.Drawing.Color.FromArgb(((int)(((byte)(106)))), ((int)(((byte)(106)))), ((int)(((byte)(106)))))});
      this.chartVoltage.ChartArea.BackInterior = new Syncfusion.Drawing.BrushInfo(System.Drawing.Color.Transparent);
      this.chartVoltage.ChartArea.CursorLocation = new System.Drawing.Point(0, 0);
      this.chartVoltage.ChartArea.CursorReDraw = false;
      this.chartVoltage.ChartInterior = new Syncfusion.Drawing.BrushInfo(System.Drawing.Color.Transparent);
      this.chartVoltage.CustomPalette = new System.Drawing.Color[] {
        System.Drawing.Color.FromArgb(((int)(((byte)(238)))), ((int)(((byte)(144)))), ((int)(((byte)(34))))),
        System.Drawing.Color.FromArgb(((int)(((byte)(107)))), ((int)(((byte)(190)))), ((int)(((byte)(82))))),
        System.Drawing.Color.FromArgb(((int)(((byte)(232)))), ((int)(((byte)(222)))), ((int)(((byte)(37))))),
        System.Drawing.Color.FromArgb(((int)(((byte)(158)))), ((int)(((byte)(66)))), ((int)(((byte)(153))))),
        System.Drawing.Color.FromArgb(((int)(((byte)(140)))), ((int)(((byte)(90)))), ((int)(((byte)(36))))),
        System.Drawing.Color.FromArgb(((int)(((byte)(221)))), ((int)(((byte)(72)))), ((int)(((byte)(38)))))};
      this.chartVoltage.DataSourceName = "batteryReadingBindingSource";
      this.chartVoltage.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(255)))), ((int)(((byte)(255)))), ((int)(((byte)(255)))));
      this.chartVoltage.IsWindowLess = false;
      // 
      // 
      // 
      this.chartVoltage.Legend.Location = new System.Drawing.Point(849, 75);
      this.chartVoltage.Localize = null;
      this.chartVoltage.Location = new System.Drawing.Point(277, 0);
      this.chartVoltage.Name = "chartVoltage";
      this.chartVoltage.Palette = Syncfusion.Windows.Forms.Chart.ChartColorPalette.Custom;
      this.chartVoltage.PrimaryXAxis.GridLineType.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(255)))), ((int)(((byte)(255)))), ((int)(((byte)(255)))));
      this.chartVoltage.PrimaryXAxis.LineType.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(255)))), ((int)(((byte)(255)))), ((int)(((byte)(255)))));
      this.chartVoltage.PrimaryXAxis.LogLabelsDisplayMode = Syncfusion.Windows.Forms.Chart.LogLabelsDisplayMode.Default;
      this.chartVoltage.PrimaryXAxis.Margin = true;
      this.chartVoltage.PrimaryXAxis.TickColor = System.Drawing.Color.FromArgb(((int)(((byte)(255)))), ((int)(((byte)(255)))), ((int)(((byte)(255)))));
      this.chartVoltage.PrimaryXAxis.Title = "mA/hour";
      this.chartVoltage.PrimaryXAxis.TitleColor = System.Drawing.SystemColors.ControlText;
      this.chartVoltage.PrimaryYAxis.GridLineType.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(255)))), ((int)(((byte)(255)))), ((int)(((byte)(255)))));
      this.chartVoltage.PrimaryYAxis.LineType.ForeColor = System.Drawing.Color.FromArgb(((int)(((byte)(255)))), ((int)(((byte)(255)))), ((int)(((byte)(255)))));
      this.chartVoltage.PrimaryYAxis.LogLabelsDisplayMode = Syncfusion.Windows.Forms.Chart.LogLabelsDisplayMode.Default;
      this.chartVoltage.PrimaryYAxis.Margin = true;
      this.chartVoltage.PrimaryYAxis.TickColor = System.Drawing.Color.FromArgb(((int)(((byte)(255)))), ((int)(((byte)(255)))), ((int)(((byte)(255)))));
      this.chartVoltage.PrimaryYAxis.Title = "Voltage";
      this.chartVoltage.PrimaryYAxis.TitleColor = System.Drawing.SystemColors.ControlText;
      chartSeries1.FancyToolTip.ResizeInsideSymbol = true;
      chartSeries1.Name = "Voltage";
      chartSeries1.Resolution = 0D;
      chartDataBindModel1.DataSource = this.batteryReadingBindingSource;
      chartDataBindModel1.XName = "mA_Hours";
      chartDataBindModel1.YNames = new string[] {
        "V_Source"};
      chartSeries1.SeriesModel = chartDataBindModel1;
      chartSeries1.StackingGroup = "Default Group";
      chartSeries1.Style.AltTagFormat = "";
      chartSeries1.Style.Border.Width = 2F;
      chartSeries1.Style.Callout.Font.Facename = "Microsoft Sans Serif";
      chartSeries1.Style.DisplayShadow = true;
      chartSeries1.Style.DrawTextShape = false;
      chartSeries1.Style.Font.Facename = "Microsoft Sans Serif";
      chartLineInfo1.Alignment = System.Drawing.Drawing2D.PenAlignment.Center;
      chartLineInfo1.Color = System.Drawing.SystemColors.ControlText;
      chartLineInfo1.DashPattern = null;
      chartLineInfo1.DashStyle = System.Drawing.Drawing2D.DashStyle.Solid;
      chartLineInfo1.Width = 1F;
      chartCustomShapeInfo1.Border = chartLineInfo1;
      chartCustomShapeInfo1.Color = System.Drawing.SystemColors.HighlightText;
      chartCustomShapeInfo1.Type = Syncfusion.Windows.Forms.Chart.ChartCustomShape.Square;
      chartSeries1.Style.TextShape = chartCustomShapeInfo1;
      chartSeries1.Text = "Voltage";
      chartSeries1.Type = Syncfusion.Windows.Forms.Chart.ChartSeriesType.Line;
      this.chartVoltage.Series.Add(chartSeries1);
      this.chartVoltage.Size = new System.Drawing.Size(955, 376);
      this.chartVoltage.TabIndex = 12;
      this.chartVoltage.Text = "Discharge";
      // 
      // 
      // 
      this.chartVoltage.Title.Name = "Default";
      this.chartVoltage.Titles.Add(this.chartVoltage.Title);
      this.chartVoltage.ToolBar.EnableDefaultItems = false;
      this.chartVoltage.ToolBar.Items.Add(chartToolBarSaveItem1);
      this.chartVoltage.ToolBar.Items.Add(chartToolBarCopyItem1);
      this.chartVoltage.ToolBar.Items.Add(chartToolBarPrintItem1);
      this.chartVoltage.ToolBar.Items.Add(chartToolBarPrintPreviewItem1);
      this.chartVoltage.ToolBar.Items.Add(chartToolBarSplitter1);
      this.chartVoltage.ToolBar.Items.Add(chartToolBarPaletteItem1);
      this.chartVoltage.ToolBar.Items.Add(chartToolBarStyleItem1);
      this.chartVoltage.ToolBar.Items.Add(chartToolBarTypeItem1);
      this.chartVoltage.ToolBar.Items.Add(chartToolBarSeries3DItem1);
      this.chartVoltage.ToolBar.Items.Add(chartToolBarShowLegendItem1);
      this.chartVoltage.VisualTheme = "";
      // 
      // button1
      // 
      this.button1.Location = new System.Drawing.Point(186, 224);
      this.button1.Name = "button1";
      this.button1.Size = new System.Drawing.Size(75, 23);
      this.button1.TabIndex = 13;
      this.button1.Text = "button1";
      this.button1.UseVisualStyleBackColor = true;
      // 
      // btnTestClear
      // 
      this.btnTestClear.Location = new System.Drawing.Point(23, 228);
      this.btnTestClear.Name = "btnTestClear";
      this.btnTestClear.Size = new System.Drawing.Size(75, 23);
      this.btnTestClear.TabIndex = 14;
      this.btnTestClear.Text = "zero";
      this.btnTestClear.UseVisualStyleBackColor = true;
      this.btnTestClear.Click += new System.EventHandler(this.btnTestClear_Click);
      // 
      // btnTestAdd
      // 
      this.btnTestAdd.Location = new System.Drawing.Point(105, 224);
      this.btnTestAdd.Name = "btnTestAdd";
      this.btnTestAdd.Size = new System.Drawing.Size(75, 23);
      this.btnTestAdd.TabIndex = 15;
      this.btnTestAdd.Text = "add";
      this.btnTestAdd.UseVisualStyleBackColor = true;
      this.btnTestAdd.Click += new System.EventHandler(this.btnTestAdd_Click);
      // 
      // numBatMaxVoltage
      // 
      this.numBatMaxVoltage.DecimalPlaces = 2;
      this.numBatMaxVoltage.Location = new System.Drawing.Point(150, 65);
      this.numBatMaxVoltage.Name = "numBatMaxVoltage";
      this.numBatMaxVoltage.Size = new System.Drawing.Size(120, 20);
      this.numBatMaxVoltage.TabIndex = 16;
      this.numBatMaxVoltage.Value = new decimal(new int[] {
            42,
            0,
            0,
            65536});
      // 
      // numBatCapacity
      // 
      this.numBatCapacity.Location = new System.Drawing.Point(150, 94);
      this.numBatCapacity.Name = "numBatCapacity";
      this.numBatCapacity.Size = new System.Drawing.Size(120, 20);
      this.numBatCapacity.TabIndex = 17;
      // 
      // label1
      // 
      this.label1.AutoSize = true;
      this.label1.Location = new System.Drawing.Point(20, 67);
      this.label1.Name = "label1";
      this.label1.Size = new System.Drawing.Size(108, 13);
      this.label1.TabIndex = 18;
      this.label1.Text = "Battery Max  Voltage:";
      // 
      // label5
      // 
      this.label5.AutoSize = true;
      this.label5.Location = new System.Drawing.Point(20, 96);
      this.label5.Name = "label5";
      this.label5.Size = new System.Drawing.Size(105, 13);
      this.label5.TabIndex = 19;
      this.label5.Text = "Battery Capacity mA:";
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
      // b_TestisRunning
      // 
      this.b_TestisRunning.DataPropertyName = "b_TestisRunning";
      this.b_TestisRunning.HeaderText = "b_TestisRunning";
      this.b_TestisRunning.Name = "b_TestisRunning";
      this.b_TestisRunning.ReadOnly = true;
      // 
      // frmMain
      // 
      this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
      this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
      this.ClientSize = new System.Drawing.Size(1244, 725);
      this.Controls.Add(this.label5);
      this.Controls.Add(this.label1);
      this.Controls.Add(this.numBatCapacity);
      this.Controls.Add(this.numBatMaxVoltage);
      this.Controls.Add(this.btnTestAdd);
      this.Controls.Add(this.btnTestClear);
      this.Controls.Add(this.button1);
      this.Controls.Add(this.chartVoltage);
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
      this.Controls.Add(this.dataGridView);
      this.Name = "frmMain";
      this.Text = "Form1";
      this.Load += new System.EventHandler(this.frmMain_Load);
      ((System.ComponentModel.ISupportInitialize)(this.dataGridView)).EndInit();
      ((System.ComponentModel.ISupportInitialize)(this.numCurrentConst)).EndInit();
      ((System.ComponentModel.ISupportInitialize)(this.numVoltageMin)).EndInit();
      ((System.ComponentModel.ISupportInitialize)(this.numBatMaxVoltage)).EndInit();
      ((System.ComponentModel.ISupportInitialize)(this.numBatCapacity)).EndInit();
      ((System.ComponentModel.ISupportInitialize)(this.batteryReadingBindingSource)).EndInit();
      this.ResumeLayout(false);
      this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.DataGridView dataGridView;
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
        private System.Windows.Forms.BindingSource batteryReadingBindingSource;
        private System.Windows.Forms.TextBox txtOutput;
    private System.Windows.Forms.Button btnBootload;
    private Syncfusion.Windows.Forms.Chart.ChartControl chartVoltage;
    private System.Windows.Forms.Button button1;
    private System.Windows.Forms.Button btnTestClear;
    private System.Windows.Forms.Button btnTestAdd;
    private System.Windows.Forms.NumericUpDown numBatMaxVoltage;
    private System.Windows.Forms.NumericUpDown numBatCapacity;
    private System.Windows.Forms.Label label1;
    private System.Windows.Forms.Label label5;
    private System.Windows.Forms.DataGridViewTextBoxColumn timeStampDataGridViewTextBoxColumn;
    private System.Windows.Forms.DataGridViewTextBoxColumn iSourceDataGridViewTextBoxColumn;
    private System.Windows.Forms.DataGridViewTextBoxColumn iLimitDataGridViewTextBoxColumn;
    private System.Windows.Forms.DataGridViewTextBoxColumn vSourceDataGridViewTextBoxColumn;
    private System.Windows.Forms.DataGridViewTextBoxColumn vMinDataGridViewTextBoxColumn;
    private System.Windows.Forms.DataGridViewTextBoxColumn mAHoursDataGridViewTextBoxColumn;
    private System.Windows.Forms.DataGridViewCheckBoxColumn b_TestisRunning;
  }
}

