using EncryptedAssemblies.Starter.Cryptography;
using Microsoft.Win32;
using System;
using System.IO;
using System.Linq;
using System.Security;
using System.Windows;

namespace EncryptedAssemblies.TestApplication
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    public partial class MainWindow : Window
    {
        public MainWindow()
        {
            InitializeComponent();
        }

        string text, pathToFile, key, keyForRemember, textForRemember;
        private static readonly SecureString _password = new SecureString();

        private void Button_Click(object sender, RoutedEventArgs e)
        {
            OpenFileDialog openFileDialog = new OpenFileDialog();
            openFileDialog.Filter = "Текстовые файлы (*.txt)|*.txt";
            if (openFileDialog.ShowDialog() == true)
            {
                pathToFile = openFileDialog.FileName;
                text = File.ReadAllText(openFileDialog.FileName);
                TextFile.Text = text;
            }
            if (String.IsNullOrEmpty(text))
                MessageBox.Show("Файл пуст");
        }

        private void Encrypt_Trismus(object sender, RoutedEventArgs e)
        {
            try
            {
                key = keyForRemember = Key.Text;
                char[] ketForPassword = key.ToCharArray();

                foreach (char c in ketForPassword)
                {
                    _password.AppendChar(c);
                }

                byte[] source = File.ReadAllBytes(pathToFile);
                CryptedData crypted = CryptographyHelper.Encrypt(source, _password);
                File.WriteAllBytes("D:\\Encrypted.txt", crypted.ToArray());

                Encrypt.Text = File.ReadAllText("D:\\Encrypted.txt");
                _password.Clear();
            }
            catch (Exception ex) { };
        }

        private void Decrypt_Trismus(object sender, RoutedEventArgs e)
        {
            try
            {
                _password.Clear();
                key = Key.Text;
                char[] ketForPassword = key.ToCharArray();

                foreach (char c in ketForPassword)
                {
                    _password.AppendChar(c);
                }

                CryptedData data;
                using (FileStream fs = File.OpenRead("D:\\Encrypted.txt"))
                {
                    data = CryptedData.Create(fs);
                }
                byte[] bytes = CryptographyHelper.Decrypt(data, _password);
                File.WriteAllBytes("D:\\Decrypted.txt", bytes.ToArray());

                Decrypt.Text = File.ReadAllText("D:\\Decrypted.txt");
                _password.Clear();
            }
            catch { };
        }

        private void Clear_ALL(object sender, RoutedEventArgs e)
        {
            Encrypt.Text = Decrypt.Text = TextFile.Text = pathToFile = null;
            File.WriteAllText(@"D:\\Decrypted.txt", string.Empty);
            File.WriteAllText(@"D:\\Encrypted.txt", string.Empty);
            _password.Clear();
        }
    }
}
