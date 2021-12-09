#pragma once
#include "Utils.h"

namespace MultiLayerNeuronNetwork {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			this->class_id_combo_box->Enabled = false;
			this->hidden_layers_num_combo_box->Enabled = false;
			this->hidden_neurons_num_combo_box->Enabled = false;
			this->set_button->ForeColor = Color::Red;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^ Coordinate_plane_PictureBox;
	protected:

	protected:
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ fileToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ readToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ writeToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ trainToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ stochasticGradientDescentSGDToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ stochasticGradientDescentWithMomentSGDToolStripMenuItem;
	private: System::Windows::Forms::GroupBox^ groupBox1;
	private: System::Windows::Forms::ComboBox^ hidden_neurons_num_combo_box;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::ComboBox^ hidden_layers_num_combo_box;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Button^ clear_lines;
	private: System::Windows::Forms::Button^ clear_all;
	private: System::Windows::Forms::ComboBox^ class_id_combo_box;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Button^ set_button;
	private: System::Windows::Forms::ComboBox^ total_classNum_combo_box;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::GroupBox^ groupBox2;
	private: System::Windows::Forms::Label^ cycle_count_label;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ x2_label;
	private: System::Windows::Forms::Label^ x1_label;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ total_sample_label;
	private: System::Windows::Forms::Label^ label3;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		/// 
		int total_class_number;
		int total_points = 0;
		Sample* points;
		int dimension = 2;
		double* weight_array;
		int weight_array_length;
		short int number_of_hidden_layers;
		short int neurons_number_in_each_hidden_layer;
		int total_layers = 0;


		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->Coordinate_plane_PictureBox = (gcnew System::Windows::Forms::PictureBox());
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->fileToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->readToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->writeToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->trainToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->stochasticGradientDescentSGDToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->stochasticGradientDescentWithMomentSGDToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->hidden_neurons_num_combo_box = (gcnew System::Windows::Forms::ComboBox());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->hidden_layers_num_combo_box = (gcnew System::Windows::Forms::ComboBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->clear_lines = (gcnew System::Windows::Forms::Button());
			this->clear_all = (gcnew System::Windows::Forms::Button());
			this->class_id_combo_box = (gcnew System::Windows::Forms::ComboBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->set_button = (gcnew System::Windows::Forms::Button());
			this->total_classNum_combo_box = (gcnew System::Windows::Forms::ComboBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->cycle_count_label = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->x2_label = (gcnew System::Windows::Forms::Label());
			this->x1_label = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->total_sample_label = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Coordinate_plane_PictureBox))->BeginInit();
			this->menuStrip1->SuspendLayout();
			this->groupBox1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->SuspendLayout();
			// 
			// Coordinate_plane_PictureBox
			// 
			this->Coordinate_plane_PictureBox->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->Coordinate_plane_PictureBox->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->Coordinate_plane_PictureBox->Cursor = System::Windows::Forms::Cursors::Hand;
			this->Coordinate_plane_PictureBox->Location = System::Drawing::Point(2, 29);
			this->Coordinate_plane_PictureBox->Name = L"Coordinate_plane_PictureBox";
			this->Coordinate_plane_PictureBox->Size = System::Drawing::Size(800, 600);
			this->Coordinate_plane_PictureBox->TabIndex = 3;
			this->Coordinate_plane_PictureBox->TabStop = false;
			this->Coordinate_plane_PictureBox->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::Coordinate_plane_PictureBox_Paint);
			this->Coordinate_plane_PictureBox->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::Coordinate_plane_PictureBox_MouseClick);
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->fileToolStripMenuItem,
					this->trainToolStripMenuItem
			});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(1184, 24);
			this->menuStrip1->TabIndex = 4;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// fileToolStripMenuItem
			// 
			this->fileToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->readToolStripMenuItem,
					this->writeToolStripMenuItem
			});
			this->fileToolStripMenuItem->Name = L"fileToolStripMenuItem";
			this->fileToolStripMenuItem->Size = System::Drawing::Size(37, 20);
			this->fileToolStripMenuItem->Text = L"File";
			// 
			// readToolStripMenuItem
			// 
			this->readToolStripMenuItem->Name = L"readToolStripMenuItem";
			this->readToolStripMenuItem->Size = System::Drawing::Size(102, 22);
			this->readToolStripMenuItem->Text = L"Read";
			// 
			// writeToolStripMenuItem
			// 
			this->writeToolStripMenuItem->Name = L"writeToolStripMenuItem";
			this->writeToolStripMenuItem->Size = System::Drawing::Size(102, 22);
			this->writeToolStripMenuItem->Text = L"Write";
			// 
			// trainToolStripMenuItem
			// 
			this->trainToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->stochasticGradientDescentSGDToolStripMenuItem,
					this->stochasticGradientDescentWithMomentSGDToolStripMenuItem
			});
			this->trainToolStripMenuItem->Name = L"trainToolStripMenuItem";
			this->trainToolStripMenuItem->Size = System::Drawing::Size(44, 20);
			this->trainToolStripMenuItem->Text = L"Train";
			// 
			// stochasticGradientDescentSGDToolStripMenuItem
			// 
			this->stochasticGradientDescentSGDToolStripMenuItem->Name = L"stochasticGradientDescentSGDToolStripMenuItem";
			this->stochasticGradientDescentSGDToolStripMenuItem->Size = System::Drawing::Size(363, 22);
			this->stochasticGradientDescentSGDToolStripMenuItem->Text = L"Stochastic Gradient Descent (SGD)";
			// 
			// stochasticGradientDescentWithMomentSGDToolStripMenuItem
			// 
			this->stochasticGradientDescentWithMomentSGDToolStripMenuItem->Name = L"stochasticGradientDescentWithMomentSGDToolStripMenuItem";
			this->stochasticGradientDescentWithMomentSGDToolStripMenuItem->Size = System::Drawing::Size(363, 22);
			this->stochasticGradientDescentWithMomentSGDToolStripMenuItem->Text = L"Stochastic Gradient Descent with Momentum (SGD_M)";
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->hidden_neurons_num_combo_box);
			this->groupBox1->Controls->Add(this->label9);
			this->groupBox1->Controls->Add(this->hidden_layers_num_combo_box);
			this->groupBox1->Controls->Add(this->label8);
			this->groupBox1->Controls->Add(this->clear_lines);
			this->groupBox1->Controls->Add(this->clear_all);
			this->groupBox1->Controls->Add(this->class_id_combo_box);
			this->groupBox1->Controls->Add(this->label2);
			this->groupBox1->Controls->Add(this->set_button);
			this->groupBox1->Controls->Add(this->total_classNum_combo_box);
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Underline)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->groupBox1->Location = System::Drawing::Point(831, 39);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(327, 381);
			this->groupBox1->TabIndex = 5;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Settings";
			// 
			// hidden_neurons_num_combo_box
			// 
			this->hidden_neurons_num_combo_box->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->hidden_neurons_num_combo_box->FormattingEnabled = true;
			this->hidden_neurons_num_combo_box->Items->AddRange(gcnew cli::array< System::Object^  >(9) {
				L"1", L"2", L"3", L"4", L"5",
					L"6", L"7", L"8", L"9"
			});
			this->hidden_neurons_num_combo_box->Location = System::Drawing::Point(25, 179);
			this->hidden_neurons_num_combo_box->Name = L"hidden_neurons_num_combo_box";
			this->hidden_neurons_num_combo_box->Size = System::Drawing::Size(80, 24);
			this->hidden_neurons_num_combo_box->TabIndex = 11;
			this->hidden_neurons_num_combo_box->Text = L"1";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Font = (gcnew System::Drawing::Font(L"Arial", 8.25F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label9->Location = System::Drawing::Point(6, 160);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(304, 13);
			this->label9->TabIndex = 10;
			this->label9->Text = L"Number Of Hidden Neurons Inside Each Hidden Layer :";
			// 
			// hidden_layers_num_combo_box
			// 
			this->hidden_layers_num_combo_box->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->hidden_layers_num_combo_box->FormattingEnabled = true;
			this->hidden_layers_num_combo_box->Items->AddRange(gcnew cli::array< System::Object^  >(9) {
				L"1", L"2", L"3", L"4", L"5",
					L"6", L"7", L"8", L"9"
			});
			this->hidden_layers_num_combo_box->Location = System::Drawing::Point(25, 112);
			this->hidden_layers_num_combo_box->Name = L"hidden_layers_num_combo_box";
			this->hidden_layers_num_combo_box->Size = System::Drawing::Size(80, 24);
			this->hidden_layers_num_combo_box->TabIndex = 9;
			this->hidden_layers_num_combo_box->Text = L"1";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Arial", 8.25F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label8->Location = System::Drawing::Point(6, 93);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(162, 13);
			this->label8->TabIndex = 8;
			this->label8->Text = L"Number Of Hidden Layer(s) :";
			// 
			// clear_lines
			// 
			this->clear_lines->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->clear_lines->Location = System::Drawing::Point(59, 336);
			this->clear_lines->Name = L"clear_lines";
			this->clear_lines->Size = System::Drawing::Size(89, 39);
			this->clear_lines->TabIndex = 7;
			this->clear_lines->Text = L"Clear Lines";
			this->clear_lines->UseVisualStyleBackColor = true;
			this->clear_lines->Click += gcnew System::EventHandler(this, &MyForm::clear_lines_Click);
			// 
			// clear_all
			// 
			this->clear_all->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->clear_all->Location = System::Drawing::Point(154, 336);
			this->clear_all->Name = L"clear_all";
			this->clear_all->Size = System::Drawing::Size(90, 39);
			this->clear_all->TabIndex = 6;
			this->clear_all->Text = L"Clear All";
			this->clear_all->UseVisualStyleBackColor = true;
			this->clear_all->Click += gcnew System::EventHandler(this, &MyForm::clear_all_Click);
			// 
			// class_id_combo_box
			// 
			this->class_id_combo_box->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->class_id_combo_box->FormattingEnabled = true;
			this->class_id_combo_box->Items->AddRange(gcnew cli::array< System::Object^  >(9) {
				L"1", L"2", L"3", L"4", L"5", L"6", L"7",
					L"8", L"9"
			});
			this->class_id_combo_box->Location = System::Drawing::Point(25, 290);
			this->class_id_combo_box->Name = L"class_id_combo_box";
			this->class_id_combo_box->Size = System::Drawing::Size(80, 24);
			this->class_id_combo_box->TabIndex = 4;
			this->class_id_combo_box->Text = L"1";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Arial", 8.25F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(6, 261);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(189, 13);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Select Class id To Add a Sample :";
			// 
			// set_button
			// 
			this->set_button->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->set_button->Location = System::Drawing::Point(8, 220);
			this->set_button->Name = L"set_button";
			this->set_button->Size = System::Drawing::Size(290, 25);
			this->set_button->TabIndex = 2;
			this->set_button->Text = L"Set";
			this->set_button->UseVisualStyleBackColor = true;
			this->set_button->Click += gcnew System::EventHandler(this, &MyForm::set_button_Click);
			// 
			// total_classNum_combo_box
			// 
			this->total_classNum_combo_box->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->total_classNum_combo_box->FormattingEnabled = true;
			this->total_classNum_combo_box->Items->AddRange(gcnew cli::array< System::Object^  >(8) {
				L"2", L"3", L"4", L"5", L"6", L"7",
					L"8", L"9"
			});
			this->total_classNum_combo_box->Location = System::Drawing::Point(25, 48);
			this->total_classNum_combo_box->Name = L"total_classNum_combo_box";
			this->total_classNum_combo_box->Size = System::Drawing::Size(80, 24);
			this->total_classNum_combo_box->TabIndex = 1;
			this->total_classNum_combo_box->Text = L"*";
			this->total_classNum_combo_box->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::total_classNum_combo_box_SelectedIndexChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Arial", 8.25F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(8, 29);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(295, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Outputs (Total Number of Classes You Want To Use) :";
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->cycle_count_label);
			this->groupBox2->Controls->Add(this->label7);
			this->groupBox2->Controls->Add(this->x2_label);
			this->groupBox2->Controls->Add(this->x1_label);
			this->groupBox2->Controls->Add(this->label6);
			this->groupBox2->Controls->Add(this->label5);
			this->groupBox2->Controls->Add(this->label4);
			this->groupBox2->Controls->Add(this->total_sample_label);
			this->groupBox2->Controls->Add(this->label3);
			this->groupBox2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Underline)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->groupBox2->Location = System::Drawing::Point(831, 426);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(328, 203);
			this->groupBox2->TabIndex = 6;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Information";
			// 
			// cycle_count_label
			// 
			this->cycle_count_label->AutoSize = true;
			this->cycle_count_label->Font = (gcnew System::Drawing::Font(L"Arial", 8.25F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->cycle_count_label->Location = System::Drawing::Point(233, 146);
			this->cycle_count_label->Name = L"cycle_count_label";
			this->cycle_count_label->Size = System::Drawing::Size(11, 13);
			this->cycle_count_label->TabIndex = 11;
			this->cycle_count_label->Text = L"-";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Sitka Small", 8.25F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label7->Location = System::Drawing::Point(7, 143);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(220, 16);
			this->label7->TabIndex = 10;
			this->label7->Text = L"Number of Cycles in Training Rules : ";
			// 
			// x2_label
			// 
			this->x2_label->AutoSize = true;
			this->x2_label->Font = (gcnew System::Drawing::Font(L"Arial", 8.25F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->x2_label->Location = System::Drawing::Point(176, 101);
			this->x2_label->Name = L"x2_label";
			this->x2_label->Size = System::Drawing::Size(11, 13);
			this->x2_label->TabIndex = 9;
			this->x2_label->Text = L"-";
			// 
			// x1_label
			// 
			this->x1_label->AutoSize = true;
			this->x1_label->Font = (gcnew System::Drawing::Font(L"Arial", 8.25F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->x1_label->Location = System::Drawing::Point(42, 104);
			this->x1_label->Name = L"x1_label";
			this->x1_label->Size = System::Drawing::Size(11, 13);
			this->x1_label->TabIndex = 8;
			this->x1_label->Text = L"-";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Sitka Small", 8.25F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label6->Location = System::Drawing::Point(6, 101);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(30, 16);
			this->label6->TabIndex = 7;
			this->label6->Text = L"X1 :";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Sitka Small", 8.25F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label5->Location = System::Drawing::Point(139, 101);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(31, 16);
			this->label5->TabIndex = 6;
			this->label5->Text = L"X2 :";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Sitka Small", 8.25F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(6, 71);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(85, 16);
			this->label4->TabIndex = 5;
			this->label4->Text = L"Coordinates :";
			// 
			// total_sample_label
			// 
			this->total_sample_label->AutoSize = true;
			this->total_sample_label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->total_sample_label->Location = System::Drawing::Point(175, 32);
			this->total_sample_label->Name = L"total_sample_label";
			this->total_sample_label->Size = System::Drawing::Size(11, 13);
			this->total_sample_label->TabIndex = 4;
			this->total_sample_label->Text = L"-";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Sitka Small", 8.25F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(6, 29);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(163, 16);
			this->label3->TabIndex = 0;
			this->label3->Text = L"Total Number Of Samples :";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1184, 641);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->Coordinate_plane_PictureBox);
			this->Controls->Add(this->menuStrip1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->MainMenuStrip = this->menuStrip1;
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Coordinate_plane_PictureBox))->EndInit();
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

//###############################################################################################################################################################################################################

	// Draw the horizontal and vertical lines on coordinate plane 
	private: System::Void Coordinate_plane_PictureBox_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
		Pen^ pen_color = gcnew Pen(Color::Black, 2.0f);
		int center_width = (int)(Coordinate_plane_PictureBox->Width / 2);
		int center_height = (int)(Coordinate_plane_PictureBox->Height / 2);
		// draw vertical line
		e->Graphics->DrawLine(pen_color, center_width, 0, center_width, Coordinate_plane_PictureBox->Height);
		// draw horizontal line
		e->Graphics->DrawLine(pen_color, 0, center_height, Coordinate_plane_PictureBox->Width, center_height);
	}


//###############################################################################################################################################################################################################

// take total number of classes, number of hidden layers and number of neurons that exist in each layer from user put it in a variables for future use
	private: System::Void set_button_Click(System::Object^ sender, System::EventArgs^ e) {
		// users only can choose number of classes between 2-9 inside combo box and if they enter anything else we give them a message to select number form combobox
		if (!check_combobox_selection((char)(Convert::ToChar(total_classNum_combo_box->Text))))
			MessageBox::Show("[Warning] you need to set the settings. (Click on set button)");
		else {
			set_button->ForeColor = Color::Blue;
			class_id_combo_box->Enabled = true;
			total_class_number = Convert::ToInt16(total_classNum_combo_box->Text);
			number_of_hidden_layers = Convert::ToInt16(hidden_layers_num_combo_box->Text);
			neurons_number_in_each_hidden_layer = Convert::ToInt16(hidden_neurons_num_combo_box->Text);


			// the rows of our weight matrix is equal to total class number and the colums are equal to inputs + 1 ( because we are going to choose our input from coordinate palne
			// the input number is always equal to 2. the +1  is because we also add bias constant to our input matrix)
			weight_array_length = total_class_number * (dimension + 1);
			weight_array = new double[weight_array_length];
		}
	}

//##############################################################################################################################################################################################################
	
	private: System::Void total_classNum_combo_box_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
		class_id_combo_box->Items->Clear();
		int items_number;
		int selected_num = Convert::ToInt16(total_classNum_combo_box->SelectedItem);
		// enable hidden_layer_num combo box, letting user to specify the number of hidden layers they want to use
		hidden_layers_num_combo_box->Enabled = true;
		hidden_layers_num_combo_box->SelectedIndex = 0;
		// enable hidden_neuron_num combobox, so user can specify how many neurons they want to use in each hidden layer
		hidden_neurons_num_combo_box->Enabled = true;
		hidden_neurons_num_combo_box->SelectedIndex = 0;

		set_button->ForeColor = Color::Red;

		switch (selected_num) {
		case 2: items_number = 2; break;
		case 3: items_number = 3; break;
		case 4: items_number = 4; break;
		case 5: items_number = 5; break;
		case 6: items_number = 6; break;
		case 7: items_number = 7; break;
		case 8: items_number = 8; break;
		case 9: items_number = 9; break;
		default: items_number = -1;
		}

		if (items_number != -1) {
			for (int i = 1; i <= items_number; i++) {
				class_id_combo_box->Items->Add(Convert::ToString(i));
			}
			class_id_combo_box->SelectedIndex = 0;
		}
		else {
			class_id_combo_box->Enabled = false;
		}
	}

//##############################################################################################################################################################################################################

	private: System::Void Coordinate_plane_PictureBox_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		if (set_button->ForeColor == Color::Blue) {


			int x1_coordinate = Convert::ToInt32(e->X);
			int x2_coordinate = Convert::ToInt32(e->Y);

			double transferred_x1 = (double)(x1_coordinate - (Coordinate_plane_PictureBox->Width / 2));
			double transferred_x2 = (double)((Coordinate_plane_PictureBox->Height / 2) - x2_coordinate);

			int class_id;
			// check if user already set total class number
			class_id = class_id_combo_box->SelectedIndex;

			//chech if the point is the first point ever added
			if (total_points == 0) {
				total_points++;
				points = new Sample[1];
				points->x_coordinates = new double[dimension];
				points[0].x_coordinates[0] = transferred_x1;
				points[0].x_coordinates[1] = transferred_x2;
				points[0].class_id = class_id;

			}
			else {
				total_points++;
				points = add_sample_to_points(points, total_points, transferred_x1, transferred_x2, class_id, dimension);
			}

			// set different color to every class according to its class id.
			Pen^ pen;
			switch (class_id) {
			case 0: pen = gcnew Pen(Color::Red, 3.0f); break;
			case 1: pen = gcnew Pen(Color::Green, 3.0f); break;
			case 2: pen = gcnew Pen(Color::Blue, 3.0f); break;
			case 3: pen = gcnew Pen(Color::Yellow, 3.0f); break;
			case 4: pen = gcnew Pen(Color::Pink, 3.0f); break;
			case 5: pen = gcnew Pen(Color::Orange, 3.0f); break;
			case 6: pen = gcnew Pen(Color::Aqua, 3.0f); break;
			case 7: pen = gcnew Pen(Color::Brown, 3.0f); break;
			case 8: pen = gcnew Pen(Color::Purple, 3.0f); break;
			default: pen = gcnew Pen(Color::Black, 3.0f);
			}

			Coordinate_plane_PictureBox->CreateGraphics()->DrawLine(pen, x1_coordinate - 5, x2_coordinate, x1_coordinate + 5, x2_coordinate);
			Coordinate_plane_PictureBox->CreateGraphics()->DrawLine(pen, x1_coordinate, x2_coordinate - 5, x1_coordinate, x2_coordinate + 5);
			total_sample_label->Text = Convert::ToString(total_points);
			x1_label->Text = Convert::ToString(transferred_x1);
			x2_label->Text = Convert::ToString(transferred_x2);
			
		}
		else {
			MessageBox::Show("You've change the settings but forget to click on Set button.");
		}
	}

//##############################################################################################################################################################################################################

	// deleting all lines (we actually clean coordinate plane by deleting all the lines and points and then draw points again)
	// this is not going to give you a good output if you ran the delta learning before because all the points are normalized, and when you redraw the points, the points will be so close together
	private: System::Void clear_lines_Click(System::Object^ sender, System::EventArgs^ e) {
		Coordinate_plane_PictureBox->Refresh();

		for (int i = 0; i < total_points; i++) {
			int pure_x = points[i].x_coordinates[0] + (Coordinate_plane_PictureBox->Width / 2);
			int pure_y = (Coordinate_plane_PictureBox->Height / 2) - points[i].x_coordinates[1];

			Pen^ pen;
			switch (points[i].class_id) {
			case 0: pen = gcnew Pen(Color::Red, 3.0f); break;
			case 1: pen = gcnew Pen(Color::Green, 3.0f); break;
			case 2: pen = gcnew Pen(Color::Blue, 3.0f); break;
			case 3: pen = gcnew Pen(Color::Yellow, 3.0f); break;
			case 4: pen = gcnew Pen(Color::Pink, 3.0f); break;
			case 5: pen = gcnew Pen(Color::Orange, 3.0f); break;
			case 6: pen = gcnew Pen(Color::Aqua, 3.0f); break;
			case 7: pen = gcnew Pen(Color::Brown, 3.0f); break;
			case 8: pen = gcnew Pen(Color::Purple, 3.0f); break;
			default: pen = gcnew Pen(Color::Black, 3.0f);
			}

			Coordinate_plane_PictureBox->CreateGraphics()->DrawLine(pen, pure_x - 5, pure_y, pure_x + 5, pure_y);
			Coordinate_plane_PictureBox->CreateGraphics()->DrawLine(pen, pure_x, pure_y - 5, pure_x, pure_y + 5);

		}
	}


//##############################################################################################################################################################################################################

	// clear coordinate plane by deleting all the lines and points 
	private: System::Void clear_all_Click(System::Object^ sender, System::EventArgs^ e) {
		Coordinate_plane_PictureBox->Refresh();
		total_points = 0;
		if(points != NULL){
			delete[]points;
			points = NULL;
		}
	}
};
}
