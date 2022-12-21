using Lab_11;
using System.Reflection;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Numerics;
using System.Runtime.Intrinsics.X86;
using System.Text;
using System.Threading.Tasks;

namespace Lab_10
{
    partial class Program
    {
        public static void Main(string[] argv)
        {
            Reflector<Person>.GetNameAssembly();
            Reflector<Person>.publicConstructor();
            Reflector<Person>.allPublicMethods();
            Reflector<Person>.getInformationAboutFielgs();
            Reflector<Employee>.getInterface();
            Reflector<Person>.GetNameOfMethods("System.Int32");
            Reflector<Person>.Invoke("Method.txt");
            var newObj = Reflector<Person>.Creator<Person>();
        }
    }
}
