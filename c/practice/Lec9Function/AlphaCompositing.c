// Description
// 在計算機圖形學領域，Alpha 合成（英語：alpha compositing）是一種將圖像與背景結合的過程，結合後可以產生部分透明或全透明的視覺效果。 (By Wikipedia)

// 在電腦當中，圖片就是一個含有一堆像素的二維陣列，每一個像素都是一個顏色，該顏色可以用數字來表示。因此，一張 m x n 大小的圖片，在電腦中可以用一個 m x n 大小的矩陣來表示。

// 要進行 Alpha 合成，必須先準備兩張圖片：一張前景 A，一張背景 B。兩張圖當中的每個像素分別以 Ca, Cb 表示，而兩張圖的透明度則分別以 Aa, Ab 表示。透明度會介於 0 到 1 之間，0 代表完全透明，1 代表完全不透明。

// 有了以上參數，我們想要計算兩張圖片合成起來之後的圖片 O，這張合成後的圖片中的每個像素以 Co 表示，則 Co 可以透過以下算式得知：

// Co = (Ca * Aa + Cb * Ab * (1 - Aa)) / (Aa + Ab * (1 - Aa))

// Alpha 合成的用處非常廣泛，例如：在渲染網頁畫面時，如果有某些畫面元件希望顯示成半透明的，可以使用 CSS 中的 opacity 濾鏡來指定元件的透明度，這個 opacity 濾鏡就是使用了Alpha合成的演算法進行畫面渲染的。

// 現在，給你一張照片 image 、這張照片的長寬 width, height、這張照片的透明度 alpha，和一個不透明純色背景的顏色 background_color，請你將這張照片跟純色背景進行 Alpha 合成。

// Input
// The first line contains foreground's alpha value (floating number range in [0, 1]), and background color (integer number range in [0, 255]).

// The second line contains width and height of the foreground image, both are integer number range in [1, 256].

// The following lines contain each pixel of the foreground image.

// Output
// The composited image.

// Limits
// Your program needs to finish task in 3 seconds.

// Your program can only use memory less than 16384 KB.

#define SIZE 256


void alpha_composite(unsigned int image[][SIZE], unsigned int width, unsigned int height, float alpha, int background_color)
{
    float alphaB = 1;
    for (int i = 0; i < height; ++i)
    {
        for (int j = 0; j < width; ++j)
        {            
            image[i][j] = (image[i][j] * alpha  + background_color * alphaB * (1-alpha)) /(alpha + alphaB * (1 - alpha));                        
        }
    }
}