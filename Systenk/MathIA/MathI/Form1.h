#pragma once

//TODO: Sett riktig verdi på DENNE
const int NO_OF_STEPS_TO_STORE = 200;

namespace CppCLRWinformsProjekt {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Zusammenfassung für Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: Konstruktorcode hier hinzufügen.
			//
		}

	protected:
		/// <summary>
		/// Verwendete Ressourcen bereinigen.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataVisualization::Charting::Chart^ chart1;

	private: System::Windows::Forms::Button^ TstDisplay;
	private: System::Void TstDisplay_Click(System::Object^ sender, System::EventArgs^ e);

		   bool sinus(float tStart, float tEnd, float fArr[2][NO_OF_STEPS_TO_STORE]);

		   bool cosinus(float tStart, float tEnd, float fArr[2][NO_OF_STEPS_TO_STORE]);

		   bool Display2(float d2dArr[2][NO_OF_STEPS_TO_STORE], int serieNr);


	private:
		/// <summary>
		/// Erforderliche Designervariable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Erforderliche Methode für die Designerunterstützung.
		/// Der Inhalt der Methode darf nicht mit dem Code-Editor geändert werden.
		/// </summary>
		void InitializeComponent(void)
		{
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea1 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^ legend1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^ series1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^ series2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			this->chart1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->TstDisplay = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->BeginInit();
			this->SuspendLayout();
			// 
			// chart1
			// 
			chartArea1->AxisX->LabelStyle->Format = L"#.##";
			chartArea1->AxisX->LabelStyle->Interval = 0.5;
			chartArea1->AxisX->ScaleBreakStyle->StartFromZero = System::Windows::Forms::DataVisualization::Charting::StartFromZero::Yes;
			chartArea1->Name = L"ChartArea1";
			this->chart1->ChartAreas->Add(chartArea1);
			legend1->Name = L"Legend1";
			this->chart1->Legends->Add(legend1);
			this->chart1->Location = System::Drawing::Point(0, -4);
			this->chart1->Name = L"chart1";
			series1->BackGradientStyle = System::Windows::Forms::DataVisualization::Charting::GradientStyle::TopBottom;
			series1->BorderColor = System::Drawing::Color::Maroon;
			series1->ChartArea = L"ChartArea1";
			series1->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Point;
			series1->Color = System::Drawing::Color::Red;
			series1->Legend = L"Legend1";
			series1->Name = L"Sinus";
			series2->ChartArea = L"ChartArea1";
			series2->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Point;
			series2->Legend = L"Legend1";
			series2->Name = L"Cosinus";
			this->chart1->Series->Add(series1);
			this->chart1->Series->Add(series2);
			this->chart1->Size = System::Drawing::Size(819, 764);
			this->chart1->TabIndex = 0;
			this->chart1->Text = L"chart1";
			// 
			// TstDisplay
			// 
			this->TstDisplay->Location = System::Drawing::Point(788, 135);
			this->TstDisplay->Name = L"TstDisplay";
			this->TstDisplay->Size = System::Drawing::Size(75, 23);
			this->TstDisplay->TabIndex = 1;
			this->TstDisplay->Text = L"TstDisplay";
			this->TstDisplay->UseVisualStyleBackColor = true;
			this->TstDisplay->Click += gcnew System::EventHandler(this, &Form1::TstDisplay_Click);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(955, 816);
			this->Controls->Add(this->TstDisplay);
			this->Controls->Add(this->chart1);
			this->Name = L"Form1";
			this->Text = L"Form1";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->EndInit();
			this->ResumeLayout(false);

		}
};
#pragma endregion
	
};
