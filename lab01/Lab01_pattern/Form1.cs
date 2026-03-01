using System;
using System.Data;
using System.Windows.Forms;
using System.Windows.Forms.DataVisualization.Charting;

namespace Lab01_pattern
{
    public partial class Form1 : Form
    {
        private IFactory factory = new BasicFactory();
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
            panel = factory.CreatePanel();
            panel.Dock = DockStyle.Fill;
            this.Controls.Add(panel);
            Label label = factory.CreateLabel();
            label.Text = "Скорость, м/с";
            label.Location = new Point(12,21);
            label.Size = new Size(147, 28);
            panel.Controls.Add(label);
            label = factory.CreateLabel();
            label.Text = "Угол, градусы";
            label.Location = new Point(162, 21);
            label.Size = new Size(137, 28);
            panel.Controls.Add(label);
            label = factory.CreateLabel();
            label.Text = "Шаг, с";
            label.Location = new Point(312, 21);
            label.Size = new Size(77, 28);
            panel.Controls.Add(label);
            label = factory.CreateLabel();
            label.Text = "Масса, кг";
            label.Location = new Point(12, 87);
            label.Size = new Size(105, 28);
            panel.Controls.Add(label);
            label = factory.CreateLabel();
            label.Text = "Сечение, м^2";
            label.Location = new Point(162, 87);
            label.Size = new Size(137, 28);
            panel.Controls.Add(label);
            label = factory.CreateLabel();
            label.Text = "Коэфф.";
            label.Location = new Point(312, 87);
            label.Size = new Size(87, 28);
            panel.Controls.Add(label);
            label = factory.CreateLabel();
            label.Text = "Стили";
            label.Location = new Point(796, 23);
            label.Size = new Size(77, 28);
            panel.Controls.Add(label);
            NumericUpDown numericupdown = factory.CreateNumericUpDown();
            numericupdown.Value = 2;
            numericupdown.DecimalPlaces = 1;
            numericupdown.Increment = 0.1m;
            numericupdown.Maximum = 100;
            numericupdown.Minimum = 0.1m;
            numericupdown.Location = new Point(12, 50);
            numericupdown.Size = new Size(120, 23);
            panel.Controls.Add(numericupdown);
            numericupdown_list[0] = numericupdown;
            numericupdown = factory.CreateNumericUpDown();
            numericupdown.Value = 45;
            numericupdown.DecimalPlaces = 1;
            numericupdown.Increment = 0.1m;
            numericupdown.Maximum = 90;
            numericupdown.Minimum = 0;
            numericupdown.Location = new Point(162, 50);
            numericupdown.Size = new Size(120, 23);
            panel.Controls.Add(numericupdown);
            numericupdown_list[1] = numericupdown;
            numericupdown = factory.CreateNumericUpDown();
            numericupdown.Value = 0.1m;
            numericupdown.DecimalPlaces = 4;
            numericupdown.Increment = 0.0001m;
            numericupdown.Maximum = 100;
            numericupdown.Minimum = 0.0001m;
            numericupdown.Location = new Point(312, 50);
            numericupdown.Size = new Size(120, 23);
            panel.Controls.Add(numericupdown);
            numericupdown_list[2] = numericupdown;
            numericupdown = factory.CreateNumericUpDown();
            numericupdown.Value = 5;
            numericupdown.DecimalPlaces = 1;
            numericupdown.Increment = 0.1m;
            numericupdown.Maximum = 100;
            numericupdown.Minimum = 0.1m;
            numericupdown.Location = new Point(12, 116);
            numericupdown.Size = new Size(120, 23);
            panel.Controls.Add(numericupdown);
            numericupdown_list[3] = numericupdown;
            numericupdown = factory.CreateNumericUpDown();
            numericupdown.Value = 10;
            numericupdown.DecimalPlaces = 1;
            numericupdown.Increment = 0.1m;
            numericupdown.Maximum = 1000;
            numericupdown.Minimum = 0.1m;
            numericupdown.Location = new Point(162, 116);
            numericupdown.Size = new Size(120, 23);
            panel.Controls.Add(numericupdown);
            numericupdown_list[4] = numericupdown;
            numericupdown = factory.CreateNumericUpDown();
            numericupdown.Value = 0.15m;
            numericupdown.DecimalPlaces = 2;
            numericupdown.Increment = 0.01m;
            numericupdown.Maximum = 1;
            numericupdown.Minimum = 0.01m;
            numericupdown.Location = new Point(312, 116);
            numericupdown.Size = new Size(120, 23);
            panel.Controls.Add(numericupdown);
            numericupdown_list[5] = numericupdown;
            chart = factory.CreateChart();
            chart.Location = new Point(12, 165);
            chart.Size = new Size(689, 384);
            panel.Controls.Add(chart);
            text_box = factory.CreateTextBox();
            text_box.Location = new Point(707, 165);
            text_box.Size = new Size(165, 384);
            panel.Controls.Add(text_box);
            Button button = factory.CreateButton();
            button.Text = "Запуск";
            button.Location = new Point(512, 32);
            button.Size = new Size(141, 41);
            button.Click += Calculate;
            panel.Controls.Add(button);
            button = factory.CreateButton();
            button.Text = "Очистка";
            button.Location = new Point(512, 98);
            button.Size = new Size(141, 41);
            button.Click += ClearChart;
            panel.Controls.Add(button);
            button = factory.CreateButton();
            button.Text = "Поменять";
            button.Location = new Point(796, 128);
            button.Size = new Size(75, 23);
            button.Click += ChangeStyle;
            panel.Controls.Add(button);
            RadioButton radio_button = factory.CreateRadioButton();
            radio_button.Text = "Базовый";
            radio_button.Location = new Point(799, 54);
            radio_button.Size = new Size(72, 19);
            if (checked_button == 1) radio_button.Checked = true;
            panel.Controls.Add(radio_button);
            radio_button_list[0] = radio_button;
            radio_button = factory.CreateRadioButton();
            radio_button.Text = "Тёмный";
            radio_button.Location = new Point(799, 79);
            radio_button.Size = new Size(69, 19);
            if (checked_button == 2) radio_button.Checked = true;
            panel.Controls.Add(radio_button);
            radio_button_list[1] = radio_button;
            radio_button = factory.CreateRadioButton();
            radio_button.Text = "Крутой";
            radio_button.Location = new Point(799, 104);
            radio_button.Size = new Size(74, 19);
            if (checked_button == 3) radio_button.Checked = true;
            panel.Controls.Add(radio_button);
            radio_button_list[2] = radio_button;
        }

        public void Clear()
        {
            while (this.Controls.Count > 0) { 
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
                factory = new BasicFactory();
                checked_button = 1;
            }
            else if (radio_button_list[1].Checked)
            {
                factory = new DarkFactory();
                checked_button = 2;
            }
            else if (radio_button_list[2].Checked)
            {
                factory = new StylishFactory();
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

    public interface IFactory 
    {
        Panel CreatePanel();
        Label CreateLabel();
        NumericUpDown CreateNumericUpDown();
        Chart CreateChart();
        TextBox CreateTextBox();
        Button CreateButton();
        RadioButton CreateRadioButton();
    }

    public class BasicFactory : IFactory 
    {
        public Panel CreatePanel() {
            return new BasicPanel();
        }

        public Label CreateLabel()
        {
            return new BasicLabel();
        }

        public NumericUpDown CreateNumericUpDown()
        {
            return new BasicNumericUpDown();
        }

        public Chart CreateChart()
        {
            return new BasicChart();
        }

        public TextBox CreateTextBox()
        {
            return new BasicTextBox();
        }

        public Button CreateButton()
        {
            return new BasicButton();
        }

        public RadioButton CreateRadioButton()
        {
            return new BasicRadioButton();
        }
    }

    public class DarkFactory : IFactory
    {
        public Panel CreatePanel()
        {
            return new DarkPanel();
        }

        public Label CreateLabel()
        {
            return new DarkLabel();
        }

        public NumericUpDown CreateNumericUpDown()
        {
            return new DarkNumericUpDown();
        }

        public Chart CreateChart()
        {
            return new DarkChart();
        }

        public TextBox CreateTextBox()
        {
            return new DarkTextBox();
        }

        public Button CreateButton()
        {
            return new DarkButton();
        }

        public RadioButton CreateRadioButton()
        {
            return new DarkRadioButton();
        }
    }

    public class StylishFactory : IFactory
    {
        public Panel CreatePanel()
        {
            return new StylishPanel();
        }

        public Label CreateLabel()
        {
            return new StylishLabel();
        }

        public NumericUpDown CreateNumericUpDown()
        {
            return new StylishNumericUpDown();
        }

        public Chart CreateChart()
        {
            return new StylishChart();
        }

        public TextBox CreateTextBox()
        {
            return new StylishTextBox();
        }

        public Button CreateButton()
        {
            return new StylishButton();
        }

        public RadioButton CreateRadioButton()
        {
            return new StylishRadioButton();
        }
    }

    public class BasicPanel : Panel 
    {
        public BasicPanel()
        {
            this.BackColor = SystemColors.Control;
        }
    }

    public class DarkPanel : Panel 
    {
        public DarkPanel() 
        {
            this.BackColor = Color.FromArgb(26, 26, 26);
        }
    }

    public class StylishPanel : Panel
    {
        public StylishPanel()
        {
            this.BackColor = Color.FromArgb(230, 0, 72);
            this.Font = new Font(this.Font, FontStyle.Italic);
        }
    }

    public class BasicLabel : Label 
    {
        public BasicLabel() 
        {
            this.Font = new Font("Segoe UI", 15);
            this.BackColor = SystemColors.Control;
            this.ForeColor = SystemColors.ControlText;
        }
    }

    public class DarkLabel : Label
    {
        public DarkLabel()
        {
            this.Font = new Font("Segoe UI", 15);
            this.BackColor = Color.FromArgb(26, 26, 26);
            this.ForeColor = SystemColors.ControlLight;
        }
    }

    public class StylishLabel : Label
    {
        public StylishLabel()
        {
            this.Font = new Font("Segoe UI", 15);
            this.BackColor = Color.FromArgb(230, 0, 72);
            this.ForeColor = Color.White;
            this.Font = new Font(this.Font, FontStyle.Italic);
        }
    }

    public class BasicNumericUpDown : NumericUpDown 
    {
        public BasicNumericUpDown() 
        {
            this.Font = new Font("Segoe UI", 9);
            this.BackColor = Color.White;
            this.ForeColor = Color.Black;
        }
    }

    public class DarkNumericUpDown : NumericUpDown
    {
        public DarkNumericUpDown()
        {
            this.Font = new Font("Segoe UI", 9);
            this.BackColor = Color.Gray;
            this.ForeColor = Color.White;
        }
    }

    public class StylishNumericUpDown : NumericUpDown
    {
        public StylishNumericUpDown()
        {
            this.Font = new Font("Segoe UI", 9);
            this.BackColor = Color.FromArgb(255, 179, 255);
            this.ForeColor = Color.White;
            this.Font = new Font(this.Font, FontStyle.Italic);
        }
    }

    public class BasicChart : Chart 
    {
        public BasicChart() 
        {
            this.Palette = ChartColorPalette.BrightPastel;
            this.BackColor = Color.White;
            this.ChartAreas.Add(new ChartArea());
            ChartArea area = this.ChartAreas[0];
            area.BackColor = Color.White;
            this.Legends.Add(new Legend());
            Legend legend = this.Legends[0];
            legend.BackColor = Color.White;
        }
    }

    public class DarkChart : Chart
    {
        public DarkChart()
        {
            this.Palette = ChartColorPalette.Bright;
            this.BackColor = Color.Gray;
            this.ChartAreas.Add(new ChartArea());
            ChartArea area = this.ChartAreas[0];
            area.BackColor = Color.Gray;
            this.Legends.Add(new Legend());
            Legend legend = this.Legends[0];
            legend.BackColor = Color.Gray;
        }
    }

    public class StylishChart : Chart
    {
        public StylishChart()
        {
            this.Palette = ChartColorPalette.Berry;
            this.BackColor = Color.FromArgb(255, 179, 255);
            this.Font = new Font(this.Font, FontStyle.Italic);
            this.ChartAreas.Add(new ChartArea());
            ChartArea area = this.ChartAreas[0];
            area.BackColor = Color.FromArgb(255, 179, 255);
            this.Legends.Add(new Legend());
            Legend legend = this.Legends[0];
            legend.BackColor = Color.FromArgb(255, 179, 255);
            legend.Font = new Font(legend.Font, FontStyle.Italic);
        }
    }

    public class BasicTextBox : TextBox 
    {
        public BasicTextBox()
        {
            this.BackColor = Color.White;
            this.ForeColor = Color.Black;
            this.Font = new Font("Segoe UI", 9);
            this.Multiline = true;
        }
    }

    public class DarkTextBox : TextBox
    {
        public DarkTextBox()
        {
            this.BackColor = Color.Gray;
            this.ForeColor = Color.White;
            this.Font = new Font("Segoe UI", 9);
            this.Multiline = true;
        }
    }

    public class StylishTextBox : TextBox
    {
        public StylishTextBox()
        {
            this.BackColor = Color.FromArgb(255, 179, 255);
            this.ForeColor = Color.White;
            this.Font = new Font("Segoe UI", 9);
            this.Multiline = true;
            this.Font = new Font(this.Font, FontStyle.Italic);
        }
    }

    public class BasicButton : Button
    {
        public BasicButton()
        {
            this.BackColor = SystemColors.Control;
            this.ForeColor = SystemColors.ControlText;
        }
    }

    public class DarkButton : Button
    {
        public DarkButton()
        {
            this.BackColor = Color.FromArgb(128, 128, 128);
            this.ForeColor = SystemColors.ControlLight;
        }
    }

    public class StylishButton : Button
    {
        public StylishButton()
        {
            this.BackColor = Color.FromArgb(255, 179, 255);
            this.ForeColor = Color.White;
            this.Font = new Font(this.Font, FontStyle.Italic);
        }
    }

    public class BasicRadioButton : RadioButton {
        public BasicRadioButton() {
            this.BackColor = SystemColors.Control;
            this.ForeColor = SystemColors.ControlText;
        }
    }

    public class DarkRadioButton : RadioButton
    {
        public DarkRadioButton()
        {
            this.BackColor = Color.FromArgb(26, 26, 26);
            this.ForeColor = SystemColors.ControlLight;
        }
    }

    public class StylishRadioButton : RadioButton
    {
        public StylishRadioButton()
        {
            this.BackColor = Color.FromArgb(230, 0, 72);
            this.ForeColor = Color.White;
            this.Font = new Font(this.Font, FontStyle.Italic);
        }
    }
}
