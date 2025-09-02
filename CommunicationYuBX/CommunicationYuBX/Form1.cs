using System;
using System.Diagnostics;
using System.IO;
using System.IO.Pipes;
using System.Text;
using System.Windows.Forms;

namespace CommunicationYuBX
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private string targetProcessName = "RobloxPlayerBeta";

        private int GetTargetPid()
        {
            Process[] procs = Process.GetProcessesByName(targetProcessName);
            if (procs.Length > 0)
                return procs[0].Id;
            return -1;
        }

        private void Executebtn_Click_1(object sender, EventArgs e)
        {
            try
            {
                string script = richTextBox1.Text;
                string[] lines = script.Split(new[] { "\r\n", "\r", "\n" }, StringSplitOptions.None);
                bool hasCode = false;
                foreach (var line in lines)
                {
                    string trimmed = line.Trim();
                    if (!string.IsNullOrEmpty(trimmed) && !trimmed.StartsWith("--"))
                    {
                        hasCode = true;
                        break;
                    }
                }

                if (!hasCode)
                {
                    MessageBox.Show("Cannot send an empty script.");
                    return;
                }

                int targetPid = GetTargetPid();
                if (targetPid == -1)
                {
                    MessageBox.Show("Target process not found.");
                    return;
                }

                string pipeName = $"YuBX_{targetPid}";

                using (var client = new NamedPipeClientStream(".", pipeName, PipeDirection.Out))
                {
                    client.Connect(5000);
                    byte[] scriptBytes = Encoding.UTF8.GetBytes(script);
                    using (var bw = new BinaryWriter(client, Encoding.UTF8, leaveOpen: true))
                    {
                        bw.Write((UInt32)scriptBytes.Length);
                        bw.Write(scriptBytes);
                        bw.Flush();
                    }
                }
            }
            catch (TimeoutException)
            {
                MessageBox.Show("Failed to connect to the pipe: Timeout.");
            }
            catch (IOException ioEx)
            {
                MessageBox.Show("Pipe error: " + ioEx.Message);
            }
            catch (Exception ex)
            {
                MessageBox.Show("Error: " + ex.Message);
            }
        }

        private void Injectbtn_Click(object sender, EventArgs e)
        {
            try
            {
                Process.Start("injector.exe");
            }
            catch (Exception ex)
            {
                MessageBox.Show("Failed to start injector: " + ex.Message);
            }
        }
    }
}
