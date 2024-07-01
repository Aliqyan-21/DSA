#include "videoListType.h"
#include "videoType.h"
#include <fstream>

void createVideoList(std::ifstream &infile, VideoListType &videoList) {
  std::string title;
  std::string star1;
  std::string star2;
  std::string producer;
  std::string director;
  std::string productionCo;
  char ch;
  int inStock;

  VideoType newVideo;

  getline(infile, title);
  while (infile) {
    getline(infile, star1);
    getline(infile, star2);
    getline(infile, producer);
    getline(infile, director);
    getline(infile, productionCo);
    infile >> inStock;
    infile.get(ch);
    newVideo.setVideoInfo(title, star1, star2, producer, director, productionCo,
                          inStock);
    videoList.insertFirst(newVideo);

    getline(infile, title);
  }
}

void displayMenu() {
  std::cout << "Select one of the following:" << std::endl;
  std::cout << "1: To check whether the store carries a "
            << "particular video." << std::endl;
  std::cout << "2: To check out a video." << std::endl;
  std::cout << "3: To check in a video." << std::endl;
  std::cout << "4: To check whether a particular video is "
            << "in stock." << std::endl;
  std::cout << "5: To print only the titles of all the videos." << std::endl;
  std::cout << "6: To print a list of all the videos." << std::endl;
  std::cout << "0: To exit" << std::endl;
}

int main(void) {
  VideoListType videoList;
  int choice;
  char ch;
  std::string title;

  std::ifstream infile;

  infile.open("videoDat.txt");
  if (!infile) {
    std::cout << "The input file does not exist" << std::endl;
    exit(1);
  }

  createVideoList(infile, videoList);
  infile.close();

  // show the menu
  displayMenu();
  std::cout << "Enter your choice: " << std::endl;
  std::cin >> choice;
  std::cin.get(ch);

  while (choice != 0) {
    switch (choice) {
    case 1:
      std::cout << "Enter the title: ";
      getline(std::cin, title);

      if (videoList.videoSearch(title))
        std::cout << "The store has the " << title << std::endl;
      else
        std::cout << "The store does not has the " << title << std::endl;
      break;

    case 2:
      std::cout << "Enter the title: ";
      getline(std::cin, title);

      if (videoList.videoSearch(title)) {
        if (videoList.isVideoAvailable(title)) {
          videoList.checkOut(title);
          std::cout << "Enjoy your movie: " << title << std::endl;
        } else
          std::cout << "Currently the movie: " << title << " is out of stock"
                    << std::endl;
      }
      break;

    case 3:
      std::cout << "Enter the title: ";
      getline(std::cin, title);

      if (videoList.videoSearch(title)) {
        videoList.checkIn(title);
        std::cout << "Thanks for returning movie: " << title << std::endl;
      } else
        std::cout << "The store does not have this title " << title
                  << std::endl;
      break;

    case 4:
      std::cout << "Enter the title: ";
      getline(std::cin, title);
      if (videoList.videoSearch(title)) {
        if (videoList.isVideoAvailable(title))
          std::cout << title << " is currently in stock." << std::endl;
        else
          std::cout << title << " is currently not in stock." << std::endl;
      } else
        std::cout << "The store does not have this title " << title
                  << std::endl;
      break;

    case 5:
      videoList.videoPrintTitle();
      break;

    case 6:
      videoList.print();
      break;

    default:
      std::cout << "invalid selection!" << std::endl;
    }
    displayMenu();
    std::cout << "Enter your choice: " << std::endl;
    std::cin >> choice;
    std::cin.get(ch);
  }
  return 0;
}
