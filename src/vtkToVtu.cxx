
#include <vtkSmartPointer.h>
#include <vtkUnstructuredGrid.h>
#include <vtkUnstructuredGridReader.h>
#include <vtkXMLUnstructuredGridWriter.h>
#include <vtkXMLUnstructuredGridReader.h>

#include <TimeIt.h>

#if TIME_IT
#include <ctime>
#endif

int main(int argc, char *argv[]) {
	if (argc != 3) {
		std::cout << "Required arguments: inputFileName outputFileName"
				<< std::endl;
		return EXIT_FAILURE;
	}

	std::cout << "Reading " << argv[1] << std::endl;

	vtkSmartPointer<vtkUnstructuredGridReader> gridReader =
			vtkSmartPointer<vtkUnstructuredGridReader>::New();
	gridReader->SetFileName(argv[1]);

#if TIME_IT
	clock_t t0 = std::clock();
#endif
	gridReader->Update();
#if TIME_IT
	clock_t t1 = clock();
	double elapsed_secs = double(t1 - t0) / CLOCKS_PER_SEC;
	std::cout << "Reading done... (elapsed time: " << elapsed_secs << ")"
			<< std::endl;
#endif

	std::cout << "Writing " << argv[2] << std::endl;

	vtkSmartPointer<vtkXMLUnstructuredGridWriter> gridWriter =
			vtkSmartPointer<vtkXMLUnstructuredGridWriter>::New();
	gridWriter->SetInputData(gridReader->GetOutput());
	gridWriter->SetFileName(argv[2]);
#if TIME_IT
	t0 = std::clock();
#endif
	gridWriter->Write();
#if TIME_IT
	t1 = clock();
	elapsed_secs = double(t1 - t0) / CLOCKS_PER_SEC;
	std::cout << "Writing done... (elapsed time: " << elapsed_secs << ")"
			<< std::endl;
#endif

#if TIME_IT
	vtkSmartPointer<vtkXMLUnstructuredGridReader> gridReReader =
			vtkSmartPointer<vtkXMLUnstructuredGridReader>::New();
	gridReReader->SetFileName(argv[2]);
	t0 = std::clock();
	gridReReader->Update();
	t1 = clock();
	elapsed_secs = double(t1 - t0) / CLOCKS_PER_SEC;

	std::cout << "Re-reading done... (elapsed time: " << elapsed_secs << ")"
			<< std::endl;
#endif

	return EXIT_SUCCESS;
}
