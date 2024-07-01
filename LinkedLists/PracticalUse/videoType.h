#ifndef VIDEOTYPE_H
#define VIDEOTYPE_H

#include <iostream>

class VideoType {
  friend std::ostream &operator<<(std::ostream &osObject,
                                  const VideoType &video) {
    osObject << std::endl;
    osObject << "Video Title: " << video.videoTitle << std::endl;
    osObject << "Stars: " << video.movieStar1 << "and" << video.movieStar2
             << std::endl;
    osObject << "Producer: " << video.movieProducer << std::endl;
    osObject << "Director: " << video.movieDirector << std::endl;
    osObject << "Production Company: " << video.movieProductionCo << std::endl;
    osObject << "Copies In Stock: " << video.copiesInStock << std::endl;
    osObject << "__________________________________________________"
             << std::endl;
    return osObject;
  }

public:
  void setVideoInfo(std::string title, std::string star1, std::string star2,
                    std::string producer, std::string director,
                    std::string productionCo, int setInStock) {
    videoTitle = title;
    movieStar1 = star1;
    movieStar2 = star2;
    movieProducer = producer;
    movieDirector = director;
    movieProductionCo = productionCo;
    copiesInStock = setInStock;
  }

  int getNoOfCopiesInStock() const { return copiesInStock; }

  void checkOut() {
    if (getNoOfCopiesInStock() > 0)
      copiesInStock--;
    else
      std::cout << "Currently out of stock." << std::endl;
  }
  void checkIn() { copiesInStock++; }

  void printTitle() const {
    std::cout << "Video Title: " << videoTitle << std::endl;
  }

  void printInfo() const {
    std::cout << "Video Title: " << videoTitle << std::endl;
    std::cout << "Stars: " << movieStar1 << "and" << movieStar2 << std::endl;
    std::cout << "Producer: " << movieProducer << std::endl;
    std::cout << "Director: " << movieDirector << std::endl;
    std::cout << "Production Company: " << movieProductionCo << std::endl;
    std::cout << "Copies In Stock: " << copiesInStock << std::endl;
  }

  bool checkTitle(std::string title) const { return (videoTitle == title); }

  void updateInStock(int num) { copiesInStock += num; }

  void setInStock(int num) { copiesInStock = num; }

  std::string getTitle() const { return videoTitle; }

  VideoType(std::string title = "", std::string star1 = "",
            std::string star2 = "", std::string producer = "",
            std::string director = "", std::string productionCo = "",
            int setInStock = 0) {
    setVideoInfo(title, star1, star2, producer, director, productionCo,
                 setInStock);
  }

  bool operator==(const VideoType &other) const {
    return (videoTitle == other.videoTitle);
  }
  bool operator!=(const VideoType &other) const {
    return (videoTitle != other.videoTitle);
  }

private:
  std::string videoTitle;
  std::string movieStar1;
  std::string movieStar2;
  std::string movieProducer;
  std::string movieDirector;
  std::string movieProductionCo;
  int copiesInStock;
};

#endif // !VIDEOTYPE_H
