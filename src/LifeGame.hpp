#ifndef __LIFEGAME_H__
#define __LIFEGAME_H__

#include<vector>

using namespace std;

namespace LifeGame{

  // --------------------------------------------------------------------------------
  // --------------------------------------------------------------------------------
  class Vec{
  public:
    size_t x;
    size_t y;

  public:
    //Vec() :x(0), y(0){}
    Vec(size_t x=0, size_t y=0) :x(x), y(y){}

    Vec(const Vec &vec) : x(vec.x), y(vec.y){}
    Vec(const Vec &&vec) : x(vec.x), y(vec.y){}
    Vec& operator=(const Vec &vec){ x = vec.x;  y = vec.y; return(*this); }
    Vec& operator=(const Vec &&vec){ x = vec.x;  y = vec.y; return(*this); }
        
    size_t GetX(){ return(x); }
    size_t GetY(){ return(y); }
  };


  // --------------------------------------------------------------------------------
  // --------------------------------------------------------------------------------
  template <std::size_t xsize, std::size_t  ysize>
  class LifeGame{
  private:
    Vec                  matrixSize;     // Cell Matrix X,Y Size

    //vector<vector<bool>> cell_matrix;    // Cell Matrix Buffer
    //vector<vector<bool>> tmpcell_matrix; // Cell Matrix Buffer2
    bool cell_matrix[xsize + 2][ysize + 2];
    bool tmpcell_matrix[xsize + 2][ysize + 2];

  public:
    LifeGame() : matrixSize(xsize, ysize) {
      //ReSizeMatrix(Vec(xsize, ysize));

      /*
      cell_matrix.resize(xsize + 2);
      tmpcell_matrix.resize(xsize + 2);
      for(auto &xx : cell_matrix)  xx.resize(ysize + 2);
      for(auto &tmpxx : tmpcell_matrix) tmpxx.resize(ysize + 2);
      */

      AllClean();

      return;
    }
    
    void AllClean(){
      /*
      for(auto &xx : cell_matrix){
      for(auto &cell : xx)
      cell = false;
      }
      */
      for(size_t xx = 0; xx < (xsize + 2); xx++){
        for(size_t yy = 0; yy < (ysize + 2); yy++){
          cell_matrix[xx][yy] = false;
          tmpcell_matrix[xx][yy] = false;
        }
      }

    }

    Vec GetMatrixSize(){
      return matrixSize;
    }

    /*
    void ResizeMatrix(const Vec vec){
      
      cell_matrix.resize(vec.x + 2); // 上下左右にスペース
      tmpcell_matrix.resize(vec.x + 2);
      for(auto &xx : cell_matrix)  xx.resize(vec.y + 2);
      for(auto &tmpxx : tmpcell_matrix) tmpxx.resize(vec.y + 2);

      matrixSize = vec;

      AllClean();

      return;
    }
    */
    
    void On(const Vec vec){
      cell_matrix[vec.x][vec.y] = true;
    }
    void Off(const Vec vec){
      cell_matrix[vec.x][vec.y] = false;
    }
    void Set(const Vec vec, const bool val){
      cell_matrix[vec.x][vec.y] = val;
    }

    bool Get(const Vec vec){
      return cell_matrix[vec.x][vec.y];
    }


    //
    //
    //
    bool IsLive(const Vec vec){
      bool result = Get(vec);  // Recent Value
      const int xx = vec.x;
      const int yy = vec.y;
      
      // Count Lived cell_matrix
      int count =
          ((cell_matrix[xx-1][yy-1]) ? 1 : 0) + ((cell_matrix[xx  ][yy-1]) ? 1 : 0) + ((cell_matrix[xx+1][yy-1]) ? 1 : 0) +
          ((cell_matrix[xx-1][yy  ]) ? 1 : 0)                                       + ((cell_matrix[xx+1][yy  ]) ? 1 : 0) +
          ((cell_matrix[xx-1][yy+1]) ? 1 : 0) + ((cell_matrix[xx  ][yy+1]) ? 1 : 0) + ((cell_matrix[xx+1][yy+1]) ? 1 : 0);

      if(cell_matrix[xx   ][yy]){
        // Live cell 
        if((count <= 1) || (count >= 4)) result = false; /// Death ///
      } else{
        // Death cell
        if(count == 3) result = true; /// Birth ///
      }
      
      //
      return result;
    }
    

    // Update CellMatrix
    //
    //
    void Update() {
      for(size_t xx = 1; xx <= xsize; xx++ ){
        for(size_t yy = 1; yy <= ysize; yy++){
          tmpcell_matrix[xx][yy] = IsLive(Vec(xx, yy));
        }
      }
      
      for(size_t xx = 1; xx <= xsize; xx++){
        for(size_t yy = 1; yy <= ysize; yy++){
          cell_matrix[xx][yy] = tmpcell_matrix[xx][yy];
        }
      }

    }
    
  };
  
}; // namespace LifeGame{

#endif // #ifndef __LIFEGAME_H__
