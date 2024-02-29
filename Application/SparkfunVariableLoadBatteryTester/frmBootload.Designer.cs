namespace SparkfunVariableLoadBatteryTester
{
  partial class frmBootload
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
      this.label3 = new System.Windows.Forms.Label();
      this.label5 = new System.Windows.Forms.Label();
      this.textBox3 = new System.Windows.Forms.TextBox();
      this.textBox5 = new System.Windows.Forms.TextBox();
      this.button1 = new System.Windows.Forms.Button();
      this.button2 = new System.Windows.Forms.Button();
      this.progressBar1 = new System.Windows.Forms.ProgressBar();
      this.openFileDialog1 = new System.Windows.Forms.OpenFileDialog();
      this.textBox6 = new System.Windows.Forms.TextBox();
      this.SuspendLayout();
      // 
      // label3
      // 
      this.label3.AutoSize = true;
      this.label3.Location = new System.Drawing.Point(458, 23);
      this.label3.Name = "label3";
      this.label3.Size = new System.Drawing.Size(79, 13);
      this.label3.TabIndex = 2;
      this.label3.Text = "USB HID State";
      // 
      // label5
      // 
      this.label5.AutoSize = true;
      this.label5.Location = new System.Drawing.Point(25, 145);
      this.label5.Name = "label5";
      this.label5.Size = new System.Drawing.Size(58, 13);
      this.label5.TabIndex = 4;
      this.label5.Text = "Status Log";
      // 
      // textBox3
      // 
      this.textBox3.Location = new System.Drawing.Point(543, 20);
      this.textBox3.Name = "textBox3";
      this.textBox3.ReadOnly = true;
      this.textBox3.Size = new System.Drawing.Size(109, 20);
      this.textBox3.TabIndex = 7;
      this.textBox3.Text = "Disconnected";
      // 
      // textBox5
      // 
      this.textBox5.Location = new System.Drawing.Point(28, 161);
      this.textBox5.Multiline = true;
      this.textBox5.Name = "textBox5";
      this.textBox5.Size = new System.Drawing.Size(402, 152);
      this.textBox5.TabIndex = 9;
      // 
      // button1
      // 
      this.button1.Location = new System.Drawing.Point(451, 52);
      this.button1.Name = "button1";
      this.button1.Size = new System.Drawing.Size(75, 23);
      this.button1.TabIndex = 10;
      this.button1.Text = "Load File";
      this.button1.UseVisualStyleBackColor = true;
      this.button1.Click += new System.EventHandler(this.button1_Click);
      // 
      // button2
      // 
      this.button2.Location = new System.Drawing.Point(545, 52);
      this.button2.Name = "button2";
      this.button2.Size = new System.Drawing.Size(75, 23);
      this.button2.TabIndex = 11;
      this.button2.Text = "Program";
      this.button2.UseVisualStyleBackColor = true;
      this.button2.Click += new System.EventHandler(this.button2_Click);
      // 
      // progressBar1
      // 
      this.progressBar1.Location = new System.Drawing.Point(28, 330);
      this.progressBar1.Name = "progressBar1";
      this.progressBar1.Size = new System.Drawing.Size(402, 23);
      this.progressBar1.TabIndex = 12;
      // 
      // openFileDialog1
      // 
      this.openFileDialog1.FileName = "openFileDialog1";
      // 
      // textBox6
      // 
      this.textBox6.Location = new System.Drawing.Point(28, 54);
      this.textBox6.Name = "textBox6";
      this.textBox6.ReadOnly = true;
      this.textBox6.Size = new System.Drawing.Size(402, 20);
      this.textBox6.TabIndex = 13;
      this.textBox6.Text = "C:\\dev\\walter\\Sparkfun Variable Load\\Variable_Load\\Firmware\\Variable_Load\\Variabl" +
    "e_Load.cydsn\\CortexM3\\ARM_GCC_541\\Debug\\Variable_Load.cyacd";
      // 
      // frmBootLoad
      // 
      this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
      this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
      this.ClientSize = new System.Drawing.Size(664, 386);
      this.Controls.Add(this.textBox6);
      this.Controls.Add(this.progressBar1);
      this.Controls.Add(this.button2);
      this.Controls.Add(this.button1);
      this.Controls.Add(this.textBox5);
      this.Controls.Add(this.textBox3);
      this.Controls.Add(this.label5);
      this.Controls.Add(this.label3);
      this.Name = "frmBootLoad";
      this.Text = "USB Bootloader Host";
      this.Load += new System.EventHandler(this.frmBootLoad_Load);
      this.ResumeLayout(false);
      this.PerformLayout();

    }


    #endregion
    private System.Windows.Forms.Label label3;
    private System.Windows.Forms.Label label5;
    private System.Windows.Forms.TextBox textBox3;
    private System.Windows.Forms.TextBox textBox5;
    private System.Windows.Forms.Button button1;
    private System.Windows.Forms.Button button2;
    private System.Windows.Forms.ProgressBar progressBar1;
    private System.Windows.Forms.OpenFileDialog openFileDialog1;
    private System.Windows.Forms.TextBox textBox6;
  }
}