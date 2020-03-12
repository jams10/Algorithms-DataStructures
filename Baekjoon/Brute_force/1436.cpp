// #include <iostream>
// #include <string>
// #include <sstream>

// bool checkSix(int number)
// {
//   std::stringstream ss;
//   ss << number;
//   std::string str = ss.str();

//   for(int i=0; i<str.length() - 2; ++i)
//   {
//     if(str[i]=='6' && str[i+1]=='6' && str[i+2]=='6')
//     {
//       return true;
//     }
//   }
//   return false;
// }

// int main()
// {
//   int index=0, number=666, count=1;
//   std::cin>>index;
//   while(true)
//   {
//     if(checkSix(number))
//     {
//       if(index==count)
//       {
//         break;
//       }
//       count++;
//     }
//     number++;
//   }
//   std::cout<<number;
// }