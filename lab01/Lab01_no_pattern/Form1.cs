using System;
using System.Data;
using System.Windows.Forms;
using System.Windows.Forms.DataVisualization.Charting;

namespace Lab01_no_pattern
{
    public partial class Form1 : Form
    {
        private Panel panel;
        private NumericUpDown[] numericupdown_list = new NumericUpDown[6];
        private Chart chart;
        private TextBox text_box;
        private RadioButton[] radio_button_list = new RadioButton[3];
        int checked_button = 1;
        private int series_amount = 0;

        public Form1()
        {
            InitializeComponent();
            Setup();
        }

        public void Setup()
        {
            Clear();
            panel = new Panel();
            panel.Dock = DockStyle.Fill;
            if (checked_button == 1) 
            {
                panel.BackColor = SystemColors.Control;
            }
            else if (checked_button == 2)
            {
                panel.BackColor = Color.FromArgb(26, 26, 26);
            }
            else
            {
                panel.BackColor = Color.FromArgb(230, 0, 72);
                panel.Font = new Font(panel.Font, FontStyle.Italic);
            }
            this.Controls.Add(panel);
            Label label = new Label();
            label.Text = "Скорость, м/с";
            label.Location = new Point(12, 21);
            label.Size = new Size(147, 28);
            if (checked_button == 1)
            {
                label.Font = new Font("Segoe UI", 15);
                label.BackColor = SystemColors.Control;
                label.ForeColor = SystemColors.ControlText;
            }
            else if (checked_button == 2)
            {
                label.Font = new Font("Segoe UI", 15);
                label.BackColor = Color.FromArgb(26, 26, 26);
                label.ForeColor = SystemColors.ControlLight;
            }
            else
            {
                label.Font = new Font("Segoe UI", 15);
                label.BackColor = Color.FromArgb(230, 0, 72);
                label.ForeColor = Color.White;
                label.Font = new Font(label.Font, FontStyle.Italic);
            }
            panel.Controls.Add(label);
            label = new Label();
            label.Text = "Угол, градусы";
            label.Location = new Point(162, 21);
            label.Size = new Size(137, 28);
            if (checked_button == 1)
            {
                label.Font = new Font("Segoe UI", 15);
                label.BackColor = SystemColors.Control;
                label.ForeColor = SystemColors.ControlText;
            }
            else if (checked_button == 2)
            {
                label.Font = new Font("Segoe UI", 15);
                label.BackColor = Color.FromArgb(26, 26, 26);
                label.ForeColor = SystemColors.ControlLight;
            }
            else
            {
                label.Font = new Font("Segoe UI", 15);
                label.BackColor = Color.FromArgb(230, 0, 72);
                label.ForeColor = Color.White;
                label.Font = new Font(label.Font, FontStyle.Italic);
            }
            panel.Controls.Add(label);
            label = new Label();
            label.Text = "Шаг, с";
            label.Location = new Point(312, 21);
            label.Size = new Size(77, 28);
            if (checked_button == 1)
            {
                label.Font = new Font("Segoe UI", 15);
                label.BackColor = SystemColors.Control;
                label.ForeColor = SystemColors.ControlText;
            }
            else if (checked_button == 2)
            {
                label.Font = new Font("Segoe UI", 15);
                label.BackColor = Color.FromArgb(26, 26, 26);
                label.ForeColor = SystemColors.ControlLight;
            }
            else
            {
                label.Font = new Font("Segoe UI", 15);
                label.BackColor = Color.FromArgb(230, 0, 72);
                label.ForeColor = Color.White;
                label.Font = new Font(label.Font, FontStyle.Italic);
            }
            panel.Controls.Add(label);
            label = new Label();
            label.Text = "Масса, кг";
            label.Location = new Point(12, 87);
            label.Size = new Size(105, 28);
            if (checked_button == 1)
            {
                label.Font = new Font("Segoe UI", 15);
                label.BackColor = SystemColors.Control;
                label.ForeColor = SystemColors.ControlText;
            }
            else if (checked_button == 2)
            {
                label.Font = new Font("Segoe UI", 15);
                label.BackColor = Color.FromArgb(26, 26, 26);
                label.ForeColor = SystemColors.ControlLight;
            }
            else
            {
                label.Font = new Font("Segoe UI", 15);
                label.BackColor = Color.FromArgb(230, 0, 72);
                label.ForeColor = Color.White;
                label.Font = new Font(label.Font, FontStyle.Italic);
            }
            panel.Controls.Add(label);
            label = new Label();
            label.Text = "Сечение, м^2";
            label.Location = new Point(162, 87);
            label.Size = new Size(137, 28);
            if (checked_button == 1)
            {
                label.Font = new Font("Segoe UI", 15);
                label.BackColor = SystemColors.Control;
                label.ForeColor = SystemColors.ControlText;
            }
            else if (checked_button == 2)
            {
                label.Font = new Font("Segoe UI", 15);
                label.BackColor = Color.FromArgb(26, 26, 26);
                label.ForeColor = SystemColors.ControlLight;
            }
            else
            {
                label.Font = new Font("Segoe UI", 15);
                label.BackColor = Color.FromArgb(230, 0, 72);
                label.ForeColor = Color.White;
                label.Font = new Font(label.Font, FontStyle.Italic);
            }
            panel.Controls.Add(label);
            label = new Label();
            label.Text = "Коэфф.";
            label.Location = new Point(312, 87);
            label.Size = new Size(87, 28);
            if (checked_button == 1)
            {
                label.Font = new Font("Segoe UI", 15);
                label.BackColor = SystemColors.Control;
                label.ForeColor = SystemColors.ControlText;
            }
            else if (checked_button == 2)
            {
                label.Font = new Font("Segoe UI", 15);
                label.BackColor = Color.FromArgb(26, 26, 26);
                label.ForeColor = SystemColors.ControlLight;
            }
            else
            {
                label.Font = new Font("Segoe UI", 15);
                label.BackColor = Color.FromArgb(230, 0, 72);
                label.ForeColor = Color.White;
                label.Font = new Font(label.Font, FontStyle.Italic);
            }
            panel.Controls.Add(label);
            label = new Label();
            label.Text = "Стили";
            label.Location = new Point(796, 23);
            label.Size = new Size(77, 28);
            if (checked_button == 1)
            {
                label.Font = new Font("Segoe UI", 15);
                label.BackColor = SystemColors.Control;
                label.ForeColor = SystemColors.ControlText;
            }
            else if (checked_button == 2)
            {
                label.Font = new Font("Segoe UI", 15);
                label.BackColor = Color.FromArgb(26, 26, 26);
                label.ForeColor = SystemColors.ControlLight;
            }
            else
            {
                label.Font = new Font("Segoe UI", 15);
                label.BackColor = Color.FromArgb(230, 0, 72);
                label.ForeColor = Color.White;
                label.Font = new Font(label.Font, FontStyle.Italic);
            }
            panel.Controls.Add(label);
            NumericUpDown numericupdown = new NumericUpDown();
            numericupdown.Value = 2;
            numericupdown.DecimalPlaces = 1;
            numericupdown.Increment = 0.1m;
            numericupdown.Maximum = 100;
            numericupdown.Minimum = 0.1m;
            numericupdown.Location = new Point(12, 50);
            numericupdown.Size = new Size(120, 23);
            if (checked_button == 1)
            {
                numericupdown.Font = new Font("Segoe UI", 9);
                numericupdown.BackColor = Color.White;
                numericupdown.ForeColor = Color.Black;
            }
            else if (checked_button == 2)
            {
                numericupdown.Font = new Font("Segoe UI", 9);
                numericupdown.BackColor = Color.Gray;
                numericupdown.ForeColor = Color.White;
            }
            else
            {
                numericupdown.Font = new Font("Segoe UI", 9);
                numericupdown.BackColor = Color.FromArgb(255, 179, 255);
                numericupdown.ForeColor = Color.White;
                numericupdown.Font = new Font(numericupdown.Font, FontStyle.Italic);
            }
            panel.Controls.Add(numericupdown);
            numericupdown_list[0] = numericupdown;
            numericupdown = new NumericUpDown();
            numericupdown.Value = 45;
            numericupdown.DecimalPlaces = 1;
            numericupdown.Increment = 0.1m;
            numericupdown.Maximum = 90;
            numericupdown.Minimum = 0;
            numericupdown.Location = new Point(162, 50);
            numericupdown.Size = new Size(120, 23);
            if (checked_button == 1)
            {
                numericupdown.Font = new Font("Segoe UI", 9);
                numericupdown.BackColor = Color.White;
                numericupdown.ForeColor = Color.Black;
            }
            else if (checked_button == 2)
            {
                numericupdown.Font = new Font("Segoe UI", 9);
                numericupdown.BackColor = Color.Gray;
                numericupdown.ForeColor = Color.White;
            }
            else
            {
                numericupdown.Font = new Font("Segoe UI", 9);
                numericupdown.BackColor = Color.FromArgb(255, 179, 255);
                numericupdown.ForeColor = Color.White;
                numericupdown.Font = new Font(numericupdown.Font, FontStyle.Italic);
            }
            panel.Controls.Add(numericupdown);
            numericupdown_list[1] = numericupdown;
            numericupdown = new NumericUpDown();
            numericupdown.Value = 0.1m;
            numericupdown.DecimalPlaces = 4;
            numericupdown.Increment = 0.0001m;
            numericupdown.Maximum = 100;
            numericupdown.Minimum = 0.0001m;
            numericupdown.Location = new Point(312, 50);
            numericupdown.Size = new Size(120, 23);
            if (checked_button == 1)
            {
                numericupdown.Font = new Font("Segoe UI", 9);
                numericupdown.BackColor = Color.White;
                numericupdown.ForeColor = Color.Black;
            }
            else if (checked_button == 2)
            {
                numericupdown.Font = new Font("Segoe UI", 9);
                numericupdown.BackColor = Color.Gray;
                numericupdown.ForeColor = Color.White;
            }
            else
            {
                numericupdown.Font = new Font("Segoe UI", 9);
                numericupdown.BackColor = Color.FromArgb(255, 179, 255);
                numericupdown.ForeColor = Color.White;
                numericupdown.Font = new Font(numericupdown.Font, FontStyle.Italic);
            }
            panel.Controls.Add(numericupdown);
            numericupdown_list[2] = numericupdown;
            numericupdown = new NumericUpDown();
            numericupdown.Value = 5;
            numericupdown.DecimalPlaces = 1;
            numericupdown.Increment = 0.1m;
            numericupdown.Maximum = 100;
            numericupdown.Minimum = 0.1m;
            numericupdown.Location = new Point(12, 116);
            numericupdown.Size = new Size(120, 23);
            if (checked_button == 1)
            {
                numericupdown.Font = new Font("Segoe UI", 9);
                numericupdown.BackColor = Color.White;
                numericupdown.ForeColor = Color.Black;
            }
            else if (checked_button == 2)
            {
                numericupdown.Font = new Font("Segoe UI", 9);
                numericupdown.BackColor = Color.Gray;
                numericupdown.ForeColor = Color.White;
            }
            else
            {
                numericupdown.Font = new Font("Segoe UI", 9);
                numericupdown.BackColor = Color.FromArgb(255, 179, 255);
                numericupdown.ForeColor = Color.White;
                numericupdown.Font = new Font(numericupdown.Font, FontStyle.Italic);
            }
            panel.Controls.Add(numericupdown);
            numericupdown_list[3] = numericupdown;
            numericupdown = new NumericUpDown();
            numericupdown.Value = 10;
            numericupdown.DecimalPlaces = 1;
            numericupdown.Increment = 0.1m;
            numericupdown.Maximum = 1000;
            numericupdown.Minimum = 0.1m;
            numericupdown.Location = new Point(162, 116);
            numericupdown.Size = new Size(120, 23);
            if (checked_button == 1)
            {
                numericupdown.Font = new Font("Segoe UI", 9);
                numericupdown.BackColor = Color.White;
                numericupdown.ForeColor = Color.Black;
            }
            else if (checked_button == 2)
            {
                numericupdown.Font = new Font("Segoe UI", 9);
                numericupdown.BackColor = Color.Gray;
                numericupdown.ForeColor = Color.White;
            }
            else
            {
                numericupdown.Font = new Font("Segoe UI", 9);
                numericupdown.BackColor = Color.FromArgb(255, 179, 255);
                numericupdown.ForeColor = Color.White;
                numericupdown.Font = new Font(numericupdown.Font, FontStyle.Italic);
            }
            panel.Controls.Add(numericupdown);
            numericupdown_list[4] = numericupdown;
            numericupdown = new NumericUpDown();
            numericupdown.Value = 0.15m;
            numericupdown.DecimalPlaces = 2;
            numericupdown.Increment = 0.01m;
            numericupdown.Maximum = 1;
            numericupdown.Minimum = 0.01m;
            numericupdown.Location = new Point(312, 116);
            numericupdown.Size = new Size(120, 23);
            if (checked_button == 1)
            {
                numericupdown.Font = new Font("Segoe UI", 9);
                numericupdown.BackColor = Color.White;
                numericupdown.ForeColor = Color.Black;
            }
            else if (checked_button == 2)
            {
                numericupdown.Font = new Font("Segoe UI", 9);
                numericupdown.BackColor = Color.Gray;
                numericupdown.ForeColor = Color.White;
            }
            else
            {
                numericupdown.Font = new Font("Segoe UI", 9);
                numericupdown.BackColor = Color.FromArgb(255, 179, 255);
                numericupdown.ForeColor = Color.White;
                numericupdown.Font = new Font(numericupdown.Font, FontStyle.Italic);
            }
            panel.Controls.Add(numericupdown);
            numericupdown_list[5] = numericupdown;
            chart = new Chart();
            chart.Location = new Point(12, 165);
            chart.Size = new Size(689, 384);
            if (checked_button == 1)
            {
                chart.Palette = ChartColorPalette.BrightPastel;
                chart.BackColor = Color.White;
                chart.ChartAreas.Add(new ChartArea());
                ChartArea area = chart.ChartAreas[0];
                area.BackColor = Color.White;
                chart.Legends.Add(new Legend());
                Legend legend = chart.Legends[0];
                legend.BackColor = Color.White;
            }
            else if (checked_button == 2)
            {
                chart.Palette = ChartColorPalette.Bright;
                chart.BackColor = Color.Gray;
                chart.ChartAreas.Add(new ChartArea());
                ChartArea area = chart.ChartAreas[0];
                area.BackColor = Color.Gray;
                chart.Legends.Add(new Legend());
                Legend legend = chart.Legends[0];
                legend.BackColor = Color.Gray;
            }
            else
            {
                chart.Palette = ChartColorPalette.Berry;
                chart.BackColor = Color.FromArgb(255, 179, 255);
                chart.Font = new Font(chart.Font, FontStyle.Italic);
                chart.ChartAreas.Add(new ChartArea());
                ChartArea area = chart.ChartAreas[0];
                area.BackColor = Color.FromArgb(255, 179, 255);
                chart.Legends.Add(new Legend());
                Legend legend = chart.Legends[0];
                legend.BackColor = Color.FromArgb(255, 179, 255);
                legend.Font = new Font(legend.Font, FontStyle.Italic);
            }
            panel.Controls.Add(chart);
            text_box = new TextBox();
            text_box.Location = new Point(707, 165);
            text_box.Size = new Size(165, 384);
            if (checked_button == 1)
            {
                text_box.BackColor = Color.White;
                text_box.ForeColor = Color.Black;
                text_box.Font = new Font("Segoe UI", 9);
                text_box.Multiline = true;
            }
            else if (checked_button == 2)
            {
                text_box.BackColor = Color.Gray;
                text_box.ForeColor = Color.White;
                text_box.Font = new Font("Segoe UI", 9);
                text_box.Multiline = true;
            }
            else
            {
                text_box.BackColor = Color.FromArgb(255, 179, 255);
                text_box.ForeColor = Color.White;
                text_box.Font = new Font("Segoe UI", 9);
                text_box.Multiline = true;
                text_box.Font = new Font(text_box.Font, FontStyle.Italic);
            }
            panel.Controls.Add(text_box);
            Button button = new Button();
            button.Text = "Запуск";
            button.Location = new Point(512, 32);
            button.Size = new Size(141, 41);
            button.Click += Calculate;
            if (checked_button == 1)
            {
                button.BackColor = SystemColors.Control;
                button.ForeColor = SystemColors.ControlText;
            }
            else if (checked_button == 2)
            {
                button.BackColor = Color.FromArgb(128, 128, 128);
                button.ForeColor = SystemColors.ControlLight;
            }
            else
            {
                button.BackColor = Color.FromArgb(255, 179, 255);
                button.ForeColor = Color.White;
                button.Font = new Font(button.Font, FontStyle.Italic);
            }
            panel.Controls.Add(button);
            button = new Button();
            button.Text = "Очистка";
            button.Location = new Point(512, 98);
            button.Size = new Size(141, 41);
            button.Click += ClearChart;
            if (checked_button == 1)
            {
                button.BackColor = SystemColors.Control;
                button.ForeColor = SystemColors.ControlText;
            }
            else if (checked_button == 2)
            {
                button.BackColor = Color.FromArgb(128, 128, 128);
                button.ForeColor = SystemColors.ControlLight;
            }
            else
            {
                button.BackColor = Color.FromArgb(255, 179, 255);
                button.ForeColor = Color.White;
                button.Font = new Font(button.Font, FontStyle.Italic);
            }
            panel.Controls.Add(button);
            button = new Button();
            button.Text = "Поменять";
            button.Location = new Point(796, 128);
            button.Size = new Size(75, 23);
            button.Click += ChangeStyle;
            if (checked_button == 1)
            {
                button.BackColor = SystemColors.Control;
                button.ForeColor = SystemColors.ControlText;
            }
            else if (checked_button == 2)
            {
                button.BackColor = Color.FromArgb(128, 128, 128);
                button.ForeColor = SystemColors.ControlLight;
            }
            else
            {
                button.BackColor = Color.FromArgb(255, 179, 255);
                button.ForeColor = Color.White;
                button.Font = new Font(button.Font, FontStyle.Italic);
            }
            panel.Controls.Add(button);
            RadioButton radio_button = new RadioButton();
            radio_button.Text = "Базовый";
            radio_button.Location = new Point(799, 54);
            radio_button.Size = new Size(72, 19);
            if (checked_button == 1) radio_button.Checked = true;
            if (checked_button == 1)
            {
                radio_button.BackColor = SystemColors.Control;
                radio_button.ForeColor = SystemColors.ControlText;
            }
            else if (checked_button == 2)
            {
                radio_button.BackColor = Color.FromArgb(26, 26, 26);
                radio_button.ForeColor = SystemColors.ControlLight;
            }
            else
            {
                radio_button.BackColor = Color.FromArgb(230, 0, 72);
                radio_button.ForeColor = Color.White;
                radio_button.Font = new Font(radio_button.Font, FontStyle.Italic);
            }
            panel.Controls.Add(radio_button);
            radio_button_list[0] = radio_button;
            radio_button = new RadioButton();
            radio_button.Text = "Тёмный";
            radio_button.Location = new Point(799, 79);
            radio_button.Size = new Size(69, 19);
            if (checked_button == 2) radio_button.Checked = true;
            if (checked_button == 1)
            {
                radio_button.BackColor = SystemColors.Control;
                radio_button.ForeColor = SystemColors.ControlText;
            }
            else if (checked_button == 2)
            {
                radio_button.BackColor = Color.FromArgb(26, 26, 26);
                radio_button.ForeColor = SystemColors.ControlLight;
            }
            else
            {
                radio_button.BackColor = Color.FromArgb(230, 0, 72);
                radio_button.ForeColor = Color.White;
                radio_button.Font = new Font(radio_button.Font, FontStyle.Italic);
            }
            panel.Controls.Add(radio_button);
            radio_button_list[1] = radio_button;
            radio_button = new RadioButton();
            radio_button.Text = "Крутой";
            radio_button.Location = new Point(799, 104);
            radio_button.Size = new Size(74, 19);
            if (checked_button == 3) radio_button.Checked = true;
            if (checked_button == 1)
            {
                radio_button.BackColor = SystemColors.Control;
                radio_button.ForeColor = SystemColors.ControlText;
            }
            else if (checked_button == 2)
            {
                radio_button.BackColor = Color.FromArgb(26, 26, 26);
                radio_button.ForeColor = SystemColors.ControlLight;
            }
            else
            {
                radio_button.BackColor = Color.FromArgb(230, 0, 72);
                radio_button.ForeColor = Color.White;
                radio_button.Font = new Font(radio_button.Font, FontStyle.Italic);
            }
            panel.Controls.Add(radio_button);
            radio_button_list[2] = radio_button;
        }

        public void Clear()
        {
            while (this.Controls.Count > 0)
            {
                Control control = this.Controls[0];
                this.Controls.RemoveAt(0);
                control.Dispose();
            }
            series_amount = 0;
        }

        private void ChangeStyle(object sender, EventArgs e)
        {
            if (radio_button_list[0].Checked)
            {
                checked_button = 1;
            }
            else if (radio_button_list[1].Checked)
            {
                checked_button = 2;
            }
            else if (radio_button_list[2].Checked)
            {
                checked_button = 3;
            }
            Setup();
        }

        private void Calculate(object sender, EventArgs e)
        {
            series_amount += 1;
            const double g = 9.8;
            double x = 0, y = 0, v0 = 0, alpha = 0, t_step = 0, vx = 0, vy = 0, max_height = 0, m = 0, S = 0, C = 0, ro = 1.29;
            v0 = (double)numericupdown_list[0].Value;
            alpha = (double)numericupdown_list[1].Value;
            t_step = (double)numericupdown_list[2].Value;
            m = (double)numericupdown_list[3].Value;
            S = (double)numericupdown_list[4].Value;
            C = (double)numericupdown_list[5].Value;
            string series_name = "Симуляция_" + series_amount.ToString();
            text_box.AppendText($"{series_name}." + Environment.NewLine);
            text_box.AppendText("Параметры:" + Environment.NewLine);
            text_box.AppendText($"Начальная скорость: {v0} м/c," + Environment.NewLine);
            text_box.AppendText($"Угол начала полёта: {alpha}°," + Environment.NewLine);
            text_box.AppendText($"Шаг моделирования: {t_step} с," + Environment.NewLine);
            text_box.AppendText($"Масса: {m} кг," + Environment.NewLine);
            text_box.AppendText($"Площадь сечения: {S} м^2," + Environment.NewLine);
            text_box.AppendText($"Коэффициент лобового сопротивления: {C}." + Environment.NewLine);
            chart.Series.Add(series_name);
            chart.Series[series_name].ChartType = System.Windows.Forms.DataVisualization.Charting.SeriesChartType.Line;
            chart.Series[series_name].Points.AddXY(x, y);
            alpha *= Math.PI / 180;
            double k = C * S * ro / (2 * m);
            vx = v0 * Math.Cos(alpha);
            vy = v0 * Math.Sin(alpha);
            double v = Math.Sqrt((vx * vx) + (vy * vy));
            do
            {
                vx = vx - k * vx * v * t_step;
                vy = vy - (g + k * vy * v) * t_step;
                v = Math.Sqrt((vx * vx) + (vy * vy));
                x = x + vx * t_step;
                y = y + vy * t_step;
                if (y > max_height) { max_height = y; }
                chart.Series[series_name].Points.AddXY(x, y);
            } while (y >= 0);
            text_box.AppendText("Результаты:" + Environment.NewLine);
            text_box.AppendText($"Дальность полёта: {Math.Round(x, 3)} м," + Environment.NewLine);
            text_box.AppendText($"Максимальная высота: {Math.Round(max_height, 3)} м," + Environment.NewLine);
            text_box.AppendText($"Скорость в конечной точке: {Math.Round(v, 3)} м/c." + Environment.NewLine);
        }

        private void ClearChart(object sender, EventArgs e)
        {
            string series_name;
            for (int i = 1; i <= series_amount; i++)
            {
                series_name = "Симуляция_" + i.ToString();
                chart.Series.Remove(chart.Series[series_name]);
            }
            series_amount = 0;
            text_box.Clear();
        }
    }
}

