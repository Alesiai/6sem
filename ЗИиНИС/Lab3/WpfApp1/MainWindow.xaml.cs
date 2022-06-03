using System;
using System.IO;
using System.Windows;
using Microsoft.Win32;

namespace WpfApp1
{
    /// <summary>
    /// Логика взаимодействия для MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        public MainWindow()
        {
            InitializeComponent();
        }

        string text;

        private void Button_Click(object sender, RoutedEventArgs e)
        {
            OpenFileDialog openFileDialog = new OpenFileDialog();
            openFileDialog.Filter = "Текстовые файлы (*.txt)|*.txt";
            if (openFileDialog.ShowDialog() == true)
            {
                text = File.ReadAllText(openFileDialog.FileName);
                TextFile.Text = text;
            }
            if (String.IsNullOrEmpty(text))
                MessageBox.Show("Файл пуст");
        }
        
        private void Encrypt_Cesare(object sender, RoutedEventArgs e)
        {
            Encrypt.Text = RoutePermutation.Encrypt(Key.Text, TextFile.Text);
        }

        private void Decrypt_Cesare(object sender, RoutedEventArgs e)
        {
            Decrypt.Text = RoutePermutation.Decrypt(Key.Text, TextFile.Text);
        }

       
        private void Encrypt_Trismus(object sender, RoutedEventArgs e)
        {   
            Encrypt.Text = MultiplePermutation.Encrypt(TextFile.Text);
        }

        private void Decrypt_Trismus(object sender, RoutedEventArgs e)
        {
            Decrypt.Text = MultiplePermutation.Decrypt(Encrypt.Text);
        }

        public static int GetNumberInThealphabet(char s)
        {
            string str = @"AaBbCcDdEeFfGgHhIiJjKkLlMmNnOoPpQqRrSsTtUuVvWwXxYyZz";

            int number = str.IndexOf(s) / 2;

            return number;
        }

        private void Clear_ALL(object sender, RoutedEventArgs e)
        {
            Encrypt.Text = Decrypt.Text = null;
        }
    }
}
