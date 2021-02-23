// Compile by either typing 'make' in the terminal 
// or manually with 'clang -lpthread painters.c -o painters'

// ===================== Include Libraries =====================
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <time.h>
// ===================== Setup our Canvas =====================
#define CANVAS_WIDTH 256
#define CANVAS_HEIGHT 256

// Our canvas is a shared piece of memory that each artist can access.
// Within our canvas, every pixel has a red, green, and blue component.
// Because we only want one artist at a time drawing on a pixel
// each pixel also has a lock associated with it.
typedef struct pixel{
	int r,g,b;
	pthread_mutex_t lock;
}pixel_t;

// Create our canvas as a global variable.
// This canvas will be shared amongst all of our threads.
pixel_t canvas[CANVAS_WIDTH][CANVAS_HEIGHT];

// ===================== Setup our Artists =====================
// This is our data structure for each artist
typedef struct artist{
	int x,y;	// Store the position of where an artist is painting
	int r,g,b;	// The color an artist paints in.
}artist_t;

// An artist can move in one of the following directions
// This is a handy abstraction, as I can 'roll an 8-sided dice'
// and depending on what value that is, move in an x and y position
// corresponding with the index below.
// e.g.
// A roll of 0 moves my artist (-1,0).
// A roll of 7 moves my artist (-1,-1)
const int moves = 8;
const int movement[][2] ={
    {-1, 0}, // to the left 
    {-1, 1}, // to the left and down
    {0, 1}, // down
    {1, 1}, // to the right and down
    {1, 0}, // to the right
    {1, -1}, // to the right and up
    {0, -1}, // up
    {-1, -1} // to the left and up
};


// This function sets up the canvas
// The purpose is to iterate through every pixel and 
// setup the initial values of the pixel and initialize the
// lock structure.
// The intent is to call this function early in main.
void initCanvas(){
	for(int x =0; x < CANVAS_WIDTH; ++x){
		for(int y =0; y < CANVAS_HEIGHT; ++y){
			canvas[x][y].r = 255;
			canvas[x][y].g = 255;
			canvas[x][y].b = 255;
			pthread_mutex_init(&canvas[x][y].lock, NULL);
		}
	}
}

// This function saves the canvas as a PPM.
// This function should be called after all painting
// operations have completed.
void outputCanvas(){
// Write out the PPM file
	// If you are looking at this solution, it could
	// be better laid out in a 'save function'
	FILE *fp;
	fp = fopen("canvas.ppm","w+");
	fputs("P3\n",fp);
	fputs("256 256\n",fp);
	fputs("255\n",fp);
	for(int x =0; x < CANVAS_WIDTH; ++x){
		for(int y =0; y < CANVAS_HEIGHT; ++y){
			fprintf(fp,"%d",canvas[x][y].r);
			fputs(" ",fp);		
			fprintf(fp,"%d",canvas[x][y].g);
			fputs(" ",fp);		
			fprintf(fp,"%d",canvas[x][y].b);
			fputs(" ",fp);		
		}
		fputs("\n",fp);
	}
	fclose(fp);	
}

// TODO: You will make code changes here.
// Here is our thread function for painting with no locking implemented.
// You may modify this code however you like.
void* paint(void* args){
    // Convert our argument structure to an artist
    artist_t* painter = (artist_t*)args;

    // Our artist will now attempt to paint 5000 strokes of paint
	// on our shared canvas
	for(int i =0; i < 5000; ++i){

        // Store our initial position
        int currentX = painter->x;
        int currentY = painter->y;
        // Generate a random number from 0-7
        int roll = (rand()%8);
        painter->x += movement[roll][0];
        painter->y += movement[roll][1];
        // Clamp the range of our movements so we only
        // paint within our 256x256 canvas.
        if(painter->x < 0) { painter->x = 0; }
        if(painter->x > CANVAS_WIDTH-1) { painter->x  = CANVAS_WIDTH-1; }
        if(painter->y < 0) { painter->y = 0; }
        if(painter->y > CANVAS_HEIGHT-1) { painter->y = CANVAS_HEIGHT-1; }
   
        // TODO: Implement some locking mechanism
        // at first glance this seems okay, but convince yourself
        // we can still have data races.
        // I suggest investigating a 'trylock'
 
        // Try to paint
        // paint the pixel if it is white.
        if( canvas[painter->x][painter->y].r == 255 &&
            canvas[painter->x][painter->y].g == 255 &&
            canvas[painter->x][painter->y].b == 255){
                canvas[painter->x][painter->y].r = painter->r;
                canvas[painter->x][painter->y].g = painter->g;
                canvas[painter->x][painter->y].b = painter->b;
        }else{
        // If we cannot paint the pixel, then we backtrack
        // to a previous pixel that we own.
            painter->x = currentX;
            painter->y = currentY;
        }
    }
}

// ================== Program Entry Point ============
int main(){
	// Initialize our 'blank' canvas
	initCanvas();
	
	// Our four expert artists
	artist_t* Michaelangelo = malloc(sizeof(artist_t));
	artist_t* Donatello  = malloc(sizeof(artist_t));
	artist_t* Raphael = malloc(sizeof(artist_t));
	artist_t* Leonardo = malloc(sizeof(artist_t));
	
	// Fill in the artist attributes
    // You will see below how this structure is used
    // as arguments passed into our thread. This is a
    // simple and organized way to pass information along.
	Michaelangelo->x = 0;
	Michaelangelo->y = 0;
	Michaelangelo->r = 255;
	Michaelangelo->g = 0;
	Michaelangelo->b = 165;
	// Fill in the artist attributes
	Donatello->x = CANVAS_WIDTH-1;
	Donatello->y = 0;
	Donatello->r = 128;
	Donatello->g = 0;
	Donatello->b = 128;
	// Fill in the artist attributes
	Raphael->x = CANVAS_WIDTH-1;
	Raphael->y = CANVAS_HEIGHT-1;
	Raphael->r = 255;
	Raphael->g = 0;
	Raphael->b = 0;	
	// Fill in the artist attributes
	Leonardo->x = 0;
	Leonardo->y = CANVAS_HEIGHT-1;
	Leonardo->r = 0;
	Leonardo->g = 0;
	Leonardo->b = 255;

    // Hold our thread id's
	pthread_t Michaelangelo_tid;
	pthread_t Donatello_tid;
	pthread_t Raphael_tid;
	pthread_t Leonardo_tid;
    // Initialize a seed for our random number generator
    srand(time(NULL));
	
	// Create our threads for each of our expert artists
	pthread_create(&Michaelangelo_tid,NULL,(void*)paint,Michaelangelo);
	pthread_create(&Donatello_tid,NULL,(void*)paint,Donatello);
	pthread_create(&Raphael_tid,NULL,(void*)paint,Raphael);
	pthread_create(&Leonardo_tid,NULL,(void*)paint,Leonardo);

    // TODO: Add 50 more artists 
    // int rookieArtists = 50;
    // pthread_t moreArtists_tid[rookieArtists];
	// artist_t* moreArtists = malloc(..);
    // for(int i =0; i < rookieArtists; ++i){

	// Join each with the main thread.  
	// Do you think our ordering of launching each thread matters?
	pthread_join(Michaelangelo_tid, NULL);		   
	pthread_join(Donatello_tid, NULL);		   
	pthread_join(Raphael_tid, NULL);		   
	pthread_join(Leonardo_tid, NULL);		   

    // TODO: Add the join the 50 other artists threads here	
    // for (...)

    // Save our canvas at the end of the painting session
	outputCanvas();
	
	// Terminate our program
    free(Michaelangelo);
    free(Donatello);
    free(Raphael);
    free(Leonardo);

    // TODO: Free any other memory you can think of

	return 0;
}
