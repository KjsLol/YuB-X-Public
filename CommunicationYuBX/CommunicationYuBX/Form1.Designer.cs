namespace CommunicationYuBX
{
    partial class Form1
    {
        /// <summary>
        ///  Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        ///  Clean up any resources being used.
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
        ///  Required method for Designer support - do not modify
        ///  the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            Executebtn = new Button();
            Injectbtn = new Button();
            richTextBox1 = new RichTextBox();
            SuspendLayout();
            // 
            // Executebtn
            // 
            Executebtn.Location = new Point(12, 363);
            Executebtn.Name = "Executebtn";
            Executebtn.Size = new Size(185, 58);
            Executebtn.TabIndex = 0;
            Executebtn.Text = "Execute";
            Executebtn.UseVisualStyleBackColor = true;
            Executebtn.Click += Executebtn_Click_1;
            // 
            // Injectbtn
            // 
            Injectbtn.Location = new Point(580, 354);
            Injectbtn.Name = "Injectbtn";
            Injectbtn.Size = new Size(185, 58);
            Injectbtn.TabIndex = 1;
            Injectbtn.Text = "Inject";
            Injectbtn.UseVisualStyleBackColor = true;
            Injectbtn.Click += Injectbtn_Click;
            // 
            // richTextBox1
            // 
            richTextBox1.Font = new Font("Segoe UI", 9.75F, FontStyle.Regular, GraphicsUnit.Point, 0);
            richTextBox1.Location = new Point(1, 11);
            richTextBox1.Name = "richTextBox1";
            richTextBox1.Size = new Size(787, 337);
            richTextBox1.TabIndex = 2;
            richTextBox1.Text = "";
            // 
            // Form1
            // 
            AutoScaleDimensions = new SizeF(7F, 15F);
            AutoScaleMode = AutoScaleMode.Font;
            ClientSize = new Size(800, 450);
            Controls.Add(richTextBox1);
            Controls.Add(Injectbtn);
            Controls.Add(Executebtn);
            Name = "Form1";
            Text = "Form1";
            ResumeLayout(false);
        }

        #endregion

        private Button Executebtn;
        private Button Injectbtn;
        private RichTextBox richTextBox1;
    }
}
