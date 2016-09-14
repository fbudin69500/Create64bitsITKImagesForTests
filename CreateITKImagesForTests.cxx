#include <itkImageFileWriter.h>
#include <iostream>

template<typename PixelType, unsigned int Dimension>
void CreateAndSave(char* filename)
{
  typedef typename itk::Image<PixelType,Dimension> ImageType;
  typename ImageType::Pointer image = ImageType::New();
  typename ImageType::SizeType size;
  size.Fill(10);
  image->SetRegions(size);
  image->Allocate();
  typedef typename itk::ImageFileWriter<ImageType> WriterType;
  typename WriterType::Pointer writer = WriterType::New();
  writer->SetFileName(filename);
  writer->SetInput(image);
  writer->Update();
}

int main(int argc, char* argv[])
{
  if(argc != 3)
  {
    std::cerr<<"Usage: "<< argv[0] << "ULongOutputFileName ULLongOutputFileName"<<std::endl;
    return 1;
  }
  CreateAndSave<unsigned long,2>(argv[1]);
  CreateAndSave<unsigned long long,2>(argv[2]);
  return 0;
}
