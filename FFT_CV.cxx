/* 
 * FFT_CV.cxx:
 * Perform FFT and IFFT operation on an image
 *
 * Author:  Nashruddin Amin
 * Website: http://www.nashruddin.com
 */

#include <stdio.h>
#include "cv.h"
#include "highgui.h"
#include "fftw3.h"

int main( int argc, char** argv )
{
    IplImage        *img1 = 0;
    IplImage        *img2 = 0;
	uchar			*img1_data;
	uchar			*img2_data;
	
    fftw_complex    *data_in;
    fftw_complex    *fft;        
    fftw_complex    *ifft;    
    fftw_plan       plan_f;
    fftw_plan       plan_b;
    
    int             width, height, step;
    int             i, j, k;
    
	/* check for supplied argument */
    if ( argc < 2 ) {
       fprintf( stderr, "Usage: fft_image <filename>\n" );
       return 1;
    }
    
    /* load original image */
    img1 = cvLoadImage( argv[1], CV_LOAD_IMAGE_GRAYSCALE );
    
	/* always check */
    if ( img1 == 0 ) {
        fprintf( stderr, "Cannot load file %s!\n", argv[1] );
        return 1;
    }
	
	/* create new image for IFFT result */
	img2 = cvCreateImage( cvSize( img1->width, img1->height ), IPL_DEPTH_8U, 1 );
	
	/* get image properties */
    width  	  = img1->width;
    height 	  = img1->height;
    step	  = img1->widthStep;
	img1_data = ( uchar* ) img1->imageData;
	img2_data = ( uchar* ) img2->imageData;    
    
    /*initialize arrays for fftw operations */
    data_in = ( fftw_complex* )fftw_malloc( sizeof( fftw_complex ) * width * height );
    fft     = ( fftw_complex* )fftw_malloc( sizeof( fftw_complex ) * width * height );
    ifft    = ( fftw_complex* )fftw_malloc( sizeof( fftw_complex ) * width * height );
	
	/* create plans */
    plan_f = fftw_plan_dft_1d( width * height, data_in, fft,  FFTW_FORWARD,  FFTW_ESTIMATE );
    plan_b = fftw_plan_dft_1d( width * height, fft,     ifft, FFTW_BACKWARD, FFTW_ESTIMATE );
    
    /* load img1's data to fftw input */
    for( i = 0, k = 0 ; i < height ; i++ ) {
        for( j = 0 ; j < width ; j++ ) {
            data_in[k][0] = ( double )img1_data[i * step + j];
            data_in[k][1] = 0.0;
            k++;
        }
    }
    
    /* perform FFT */
    fftw_execute( plan_f );
    
    /* perform IFFT */
    fftw_execute( plan_b );
    
    /* normalize IFFT result */
    for( i = 0 ; i < ( width * height ) ; i++ ) {
        ifft[i][0] /= ( double )( width * height );
    }
    
    /* copy IFFT result to img2's data */
    for( i = 0, k = 0 ; i < height ; i++ ) {
		for( j = 0 ; j < width ; j++ ) {
			img2_data[i * step + j] = ( uchar )ifft[k++][0];
		}
	}
    
	/* display images */
    cvNamedWindow( "original_image", CV_WINDOW_AUTOSIZE );
    cvNamedWindow( "IFFT", CV_WINDOW_AUTOSIZE );
    cvShowImage( "original_image", img1 );
    cvShowImage( "IFFT", img2 );
    
	cvWaitKey( 0 );

	/* free memory */
	cvDestroyWindow( "original_image" );
    cvDestroyWindow( "IFFT" );
	cvReleaseImage( &img1 );
	cvReleaseImage( &img2 );
    fftw_destroy_plan( plan_f );
    fftw_destroy_plan( plan_b );
    fftw_free( data_in );
    fftw_free( fft );
    fftw_free( ifft );
    
    return 0;
}
