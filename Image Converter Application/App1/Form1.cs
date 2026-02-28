using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Drawing.Imaging;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace App1
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }
        Bitmap img;
        Bitmap[] images = new Bitmap[32];
        Byte[] Loaded_images = new Byte[32];
        Color[,] Seg_colors = new Color[32,7];
            
        public Image Resize(Image source, int width, int height)

        {

            if (source.Width == width && source.Height == height) return source;

            var result = new Bitmap(width, height, PixelFormat.Format24bppRgb);

            result.SetResolution(source.HorizontalResolution, source.VerticalResolution);

            using (var g = Graphics.FromImage(result))

                g.DrawImage(source, new Rectangle(0, 0, width, height), new Rectangle(0, 0, source.Width, source.Height), GraphicsUnit.Pixel);

            return result;

        }





        private void button1_Click(object sender, EventArgs e)
        {
 
            openFileDialog1.Filter = "Picture |*.bmp;*.jpg;*.jpeg;*.png";
            if (openFileDialog1.ShowDialog() == DialogResult.OK)
            {
                img = (Bitmap)Resize(new Bitmap(openFileDialog1.FileName), 480, 272);
                pictureBox1.Image = img;               
            }

        }





        private void Form1_Load(object sender, EventArgs e)
        {

        }


        



        private void button3_Click(object sender, EventArgs e)
        {
            if(pictureBox1.Image!=null)
            {
                saveFileDialog1.Filter = "RGB |*.rgb";
                if (saveFileDialog1.ShowDialog() == DialogResult.OK)
                {
                    this.Cursor = Cursors.WaitCursor;
                    this.UseWaitCursor = true;

                    using (System.IO.FileStream fs = System.IO.File.Create(saveFileDialog1.FileName))
                    {
                        int i = 0;
                        char[] ss = new char[10];
                        ss = "M.H.Najafi".ToCharArray();
                        //Write Name
                        for (i = 0; i < 10; i++) fs.WriteByte(Convert.ToByte(ss[i]));

                        Bitmap tmp = new Bitmap(480, 272, PixelFormat.Format24bppRgb);
                        Color clr;
                        Byte R, G, B;
                        Byte Dl, Dh;

                        tmp = (Bitmap)pictureBox1.Image;

                        for (int m = 0; m < 272; m++)
                        {
                            for (int n = 0; n < 480; n++)
                            {
                                clr = tmp.GetPixel(n, m);
                                R = clr.R;
                                G = clr.G;
                                B = clr.B;

                                Dh = Convert.ToByte((B & 0xF8) | ((G >> 5) & 0x07));
                                Dl = Convert.ToByte(((G << 3) & 0xE0) | ((R >> 3) & 0x1F));
                                fs.WriteByte(Dh);
                                fs.WriteByte(Dl);

                            }

                        }
                        this.UseWaitCursor = false;
                        this.Cursor = Cursors.Default;
                        MessageBox.Show("ذخیره سازی تکمیل شد!");
                    }
                }
            }


            
            
        }




    }
}
