#pragma once
#include<raylib.h>
#include"Visualizer.h"

enum sortAlgo{Bubble , Insertion , Selective , Quick , Merge , None};

namespace TestingWithNetFramework {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MainForm
	/// </summary>
	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MainForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ button_bubbleSort;
	protected:

	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Button^ button_quickSort;
	private: System::Windows::Forms::Button^ button_mergeSort;


	private: System::Windows::Forms::Button^ button_selectiveSort;

	private: System::Windows::Forms::Button^ button_insertionSort;
	private: System::Windows::Forms::Button^ button_startVisualizer;

	private: sortAlgo sortState = sortAlgo::None;


	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button_bubbleSort = (gcnew System::Windows::Forms::Button());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->button_quickSort = (gcnew System::Windows::Forms::Button());
			this->button_mergeSort = (gcnew System::Windows::Forms::Button());
			this->button_selectiveSort = (gcnew System::Windows::Forms::Button());
			this->button_insertionSort = (gcnew System::Windows::Forms::Button());
			this->button_startVisualizer = (gcnew System::Windows::Forms::Button());
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Tai Le", 18, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Underline)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::White;
			this->label1->Location = System::Drawing::Point(26, 28);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(385, 39);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Choose Sorting Algorithm";
			// 
			// button_bubbleSort
			// 
			this->button_bubbleSort->BackColor = System::Drawing::Color::Cyan;
			this->button_bubbleSort->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button_bubbleSort->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button_bubbleSort->ForeColor = System::Drawing::Color::Navy;
			this->button_bubbleSort->Location = System::Drawing::Point(66, 91);
			this->button_bubbleSort->Name = L"button_bubbleSort";
			this->button_bubbleSort->Size = System::Drawing::Size(313, 65);
			this->button_bubbleSort->TabIndex = 1;
			this->button_bubbleSort->Text = L"Bubble Sort";
			this->button_bubbleSort->UseVisualStyleBackColor = false;
			this->button_bubbleSort->Click += gcnew System::EventHandler(this, &MainForm::button_bubbleSort_Click);
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(20)), static_cast<System::Int32>(static_cast<System::Byte>(20)),
				static_cast<System::Int32>(static_cast<System::Byte>(20)));
			this->panel1->Controls->Add(this->button_quickSort);
			this->panel1->Controls->Add(this->button_mergeSort);
			this->panel1->Controls->Add(this->button_selectiveSort);
			this->panel1->Controls->Add(this->button_insertionSort);
			this->panel1->Controls->Add(this->button_bubbleSort);
			this->panel1->Controls->Add(this->label1);
			this->panel1->Location = System::Drawing::Point(232, 31);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(441, 580);
			this->panel1->TabIndex = 2;
			// 
			// button_quickSort
			// 
			this->button_quickSort->BackColor = System::Drawing::Color::Cyan;
			this->button_quickSort->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button_quickSort->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button_quickSort->ForeColor = System::Drawing::Color::Navy;
			this->button_quickSort->Location = System::Drawing::Point(66, 396);
			this->button_quickSort->Name = L"button_quickSort";
			this->button_quickSort->Size = System::Drawing::Size(313, 65);
			this->button_quickSort->TabIndex = 5;
			this->button_quickSort->Text = L"Quick Sort";
			this->button_quickSort->UseVisualStyleBackColor = false;
			this->button_quickSort->Click += gcnew System::EventHandler(this, &MainForm::button_quickSort_Click);
			// 
			// button_mergeSort
			// 
			this->button_mergeSort->BackColor = System::Drawing::Color::Cyan;
			this->button_mergeSort->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button_mergeSort->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button_mergeSort->ForeColor = System::Drawing::Color::Navy;
			this->button_mergeSort->Location = System::Drawing::Point(66, 498);
			this->button_mergeSort->Name = L"button_mergeSort";
			this->button_mergeSort->Size = System::Drawing::Size(313, 65);
			this->button_mergeSort->TabIndex = 4;
			this->button_mergeSort->Text = L"Merge Sort";
			this->button_mergeSort->UseVisualStyleBackColor = false;
			this->button_mergeSort->Click += gcnew System::EventHandler(this, &MainForm::button_mergeSort_Click);
			// 
			// button_selectiveSort
			// 
			this->button_selectiveSort->BackColor = System::Drawing::Color::Cyan;
			this->button_selectiveSort->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button_selectiveSort->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button_selectiveSort->ForeColor = System::Drawing::Color::Navy;
			this->button_selectiveSort->Location = System::Drawing::Point(66, 292);
			this->button_selectiveSort->Name = L"button_selectiveSort";
			this->button_selectiveSort->Size = System::Drawing::Size(313, 65);
			this->button_selectiveSort->TabIndex = 3;
			this->button_selectiveSort->Text = L"Selective Sort";
			this->button_selectiveSort->UseVisualStyleBackColor = false;
			this->button_selectiveSort->Click += gcnew System::EventHandler(this, &MainForm::button_selectiveSort_Click);
			// 
			// button_insertionSort
			// 
			this->button_insertionSort->BackColor = System::Drawing::Color::Cyan;
			this->button_insertionSort->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button_insertionSort->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button_insertionSort->ForeColor = System::Drawing::Color::Navy;
			this->button_insertionSort->Location = System::Drawing::Point(66, 190);
			this->button_insertionSort->Name = L"button_insertionSort";
			this->button_insertionSort->Size = System::Drawing::Size(313, 65);
			this->button_insertionSort->TabIndex = 2;
			this->button_insertionSort->Text = L"Insertion Sort";
			this->button_insertionSort->UseVisualStyleBackColor = false;
			this->button_insertionSort->Click += gcnew System::EventHandler(this, &MainForm::button_insertionSort_Click);
			// 
			// button_startVisualizer
			// 
			this->button_startVisualizer->BackColor = System::Drawing::Color::Silver;
			this->button_startVisualizer->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button_startVisualizer->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Bold,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->button_startVisualizer->ForeColor = System::Drawing::Color::Purple;
			this->button_startVisualizer->Location = System::Drawing::Point(891, 268);
			this->button_startVisualizer->Name = L"button_startVisualizer";
			this->button_startVisualizer->Size = System::Drawing::Size(283, 98);
			this->button_startVisualizer->TabIndex = 6;
			this->button_startVisualizer->Text = L"Start Visualizer";
			this->button_startVisualizer->UseVisualStyleBackColor = false;
			this->button_startVisualizer->Click += gcnew System::EventHandler(this, &MainForm::button_startVisualizer_Click);
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::Black;
			this->ClientSize = System::Drawing::Size(1225, 653);
			this->Controls->Add(this->button_startVisualizer);
			this->Controls->Add(this->panel1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
			this->Name = L"MainForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"MainForm";
			this->Load += gcnew System::EventHandler(this, &MainForm::MainForm_Load);
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	
	private: void updateSortButtons() {
		button_bubbleSort->BackColor = System::Drawing::Color::Cyan;
		button_insertionSort->BackColor = System::Drawing::Color::Cyan;
		button_selectiveSort->BackColor = System::Drawing::Color::Cyan;
		button_quickSort->BackColor = System::Drawing::Color::Cyan;
		button_mergeSort->BackColor = System::Drawing::Color::Cyan;

		if(sortState == sortAlgo::Bubble) { button_bubbleSort->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(178)), static_cast<System::Int32>(static_cast<System::Byte>(235)),static_cast<System::Int32>(static_cast<System::Byte>(0)));}
		if (sortState == sortAlgo::Insertion) { button_insertionSort->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(178)), static_cast<System::Int32>(static_cast<System::Byte>(235)), static_cast<System::Int32>(static_cast<System::Byte>(0))); }
		if (sortState == sortAlgo::Selective) { button_selectiveSort->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(178)), static_cast<System::Int32>(static_cast<System::Byte>(235)), static_cast<System::Int32>(static_cast<System::Byte>(0))); }
		if (sortState == sortAlgo::Quick) { button_quickSort->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(178)), static_cast<System::Int32>(static_cast<System::Byte>(235)), static_cast<System::Int32>(static_cast<System::Byte>(0))); }
		if (sortState == sortAlgo::Merge) { button_mergeSort->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(178)), static_cast<System::Int32>(static_cast<System::Byte>(235)), static_cast<System::Int32>(static_cast<System::Byte>(0))); }

	}

	private: System::Void MainForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}

private: System::Void button_bubbleSort_Click(System::Object^ sender, System::EventArgs^ e) {
	sortState = sortAlgo::Bubble;
	updateSortButtons();
}	
private: System::Void button_insertionSort_Click(System::Object^ sender, System::EventArgs^ e) {
	sortState = sortAlgo::Insertion;
	updateSortButtons();
}
private: System::Void button_selectiveSort_Click(System::Object^ sender, System::EventArgs^ e) {
	sortState = sortAlgo::Selective;
	updateSortButtons();
}
private: System::Void button_quickSort_Click(System::Object^ sender, System::EventArgs^ e) {
	sortState = sortAlgo::Quick;
	updateSortButtons();
}
private: System::Void button_mergeSort_Click(System::Object^ sender, System::EventArgs^ e) {
	sortState = sortAlgo::Merge;
	updateSortButtons();
}



private: System::Void button_startVisualizer_Click(System::Object^ sender, System::EventArgs^ e) {
	if (sortState == sortAlgo::None) {
		return;
	}

	StartVisualizer(sortState);
	
	Application::Restart();
}
};
}
