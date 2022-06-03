namespace WpfApp1
{
    class CharNum
    {
        #region Fields
        /// <summary>
        /// Символ.
        /// </summary>
        private char _ch;
        /// <summary>
        /// Порядковый номер зависящий от алфавита.
        /// </summary>
        private int _numberInWord;
        #endregion Fieds

        #region Properties
        /// <summary>
        /// Символ.
        /// </summary>
        public char Ch
        {
            get { return _ch; }
            set
            {
                if (_ch == value)
                    return;
                _ch = value;
            }
        }
        /// <summary>
        /// Порядковый номер в строке, зависящий от алфавита.
        /// </summary>
        public int NumberInWord
        {
            get { return _numberInWord; }
            set
            {
                if (_numberInWord == value)
                    return;
                _numberInWord = value;
            }
        }
        #endregion Properties
    }
}
