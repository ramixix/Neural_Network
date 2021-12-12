#pragma once
#include "Network.h"

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
			this->Training_type_combo_box->Enabled = false;
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
		int train_type;
	private: System::Windows::Forms::Label^ Error_lable;
	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::Label^ output_layer_label;

	private: System::Windows::Forms::Label^ hidden_layers_label;


	private: System::Windows::Forms::Label^ input_label;
	private: System::Windows::Forms::Label^ label14;
	private: System::Windows::Forms::Label^ label13;
	private: System::Windows::Forms::Label^ label12;
	private: System::Windows::Forms::Label^ label11;
	private: System::Windows::Forms::ComboBox^ Training_type_combo_box;
	private: System::Windows::Forms::Label^ label15;
	private: System::Windows::Forms::Button^ start_training_button;



		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		/// 

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
			this->start_training_button = (gcnew System::Windows::Forms::Button());
			this->Training_type_combo_box = (gcnew System::Windows::Forms::ComboBox());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->hidden_neurons_num_combo_box = (gcnew System::Windows::Forms::ComboBox());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->hidden_layers_num_combo_box = (gcnew System::Windows::Forms::ComboBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->clear_all = (gcnew System::Windows::Forms::Button());
			this->class_id_combo_box = (gcnew System::Windows::Forms::ComboBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->set_button = (gcnew System::Windows::Forms::Button());
			this->total_classNum_combo_box = (gcnew System::Windows::Forms::ComboBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->output_layer_label = (gcnew System::Windows::Forms::Label());
			this->hidden_layers_label = (gcnew System::Windows::Forms::Label());
			this->input_label = (gcnew System::Windows::Forms::Label());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->Error_lable = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
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
			this->Coordinate_plane_PictureBox->Size = System::Drawing::Size(800, 700);
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
			this->menuStrip1->Size = System::Drawing::Size(1234, 24);
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
			this->stochasticGradientDescentSGDToolStripMenuItem->Click += gcnew System::EventHandler(this, &MyForm::stochasticGradientDescentSGDToolStripMenuItem_Click);
			// 
			// stochasticGradientDescentWithMomentSGDToolStripMenuItem
			// 
			this->stochasticGradientDescentWithMomentSGDToolStripMenuItem->Name = L"stochasticGradientDescentWithMomentSGDToolStripMenuItem";
			this->stochasticGradientDescentWithMomentSGDToolStripMenuItem->Size = System::Drawing::Size(363, 22);
			this->stochasticGradientDescentWithMomentSGDToolStripMenuItem->Text = L"Stochastic Gradient Descent with Momentum (SGD_M)";
			// 
			// groupBox1
			// 
			this->groupBox1->Controls->Add(this->start_training_button);
			this->groupBox1->Controls->Add(this->Training_type_combo_box);
			this->groupBox1->Controls->Add(this->label15);
			this->groupBox1->Controls->Add(this->hidden_neurons_num_combo_box);
			this->groupBox1->Controls->Add(this->label9);
			this->groupBox1->Controls->Add(this->hidden_layers_num_combo_box);
			this->groupBox1->Controls->Add(this->label8);
			this->groupBox1->Controls->Add(this->clear_all);
			this->groupBox1->Controls->Add(this->class_id_combo_box);
			this->groupBox1->Controls->Add(this->label2);
			this->groupBox1->Controls->Add(this->set_button);
			this->groupBox1->Controls->Add(this->total_classNum_combo_box);
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Underline)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->groupBox1->Location = System::Drawing::Point(827, 29);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(383, 462);
			this->groupBox1->TabIndex = 5;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Settings";
			// 
			// start_training_button
			// 
			this->start_training_button->Font = (gcnew System::Drawing::Font(L"Sitka Small", 11.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->start_training_button->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->start_training_button->Location = System::Drawing::Point(11, 397);
			this->start_training_button->Name = L"start_training_button";
			this->start_training_button->Size = System::Drawing::Size(258, 59);
			this->start_training_button->TabIndex = 14;
			this->start_training_button->Text = L"Train";
			this->start_training_button->UseVisualStyleBackColor = true;
			this->start_training_button->Click += gcnew System::EventHandler(this, &MyForm::start_training_button_Click);
			// 
			// Training_type_combo_box
			// 
			this->Training_type_combo_box->Font = (gcnew System::Drawing::Font(L"Arial", 8.25F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->Training_type_combo_box->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->Training_type_combo_box->FormattingEnabled = true;
			this->Training_type_combo_box->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->Training_type_combo_box->Items->AddRange(gcnew cli::array< System::Object^  >(2) {
				L"Stochastic Gradient Descent (SGD)",
					L"Stochastic Gradient Descent with Momentum (SGD_M)"
			});
			this->Training_type_combo_box->Location = System::Drawing::Point(16, 246);
			this->Training_type_combo_box->Name = L"Training_type_combo_box";
			this->Training_type_combo_box->Size = System::Drawing::Size(355, 21);
			this->Training_type_combo_box->TabIndex = 13;
			this->Training_type_combo_box->Text = L"None";
			// 
			// label15
			// 
			this->label15->AutoSize = true;
			this->label15->Font = (gcnew System::Drawing::Font(L"Arial", 8.25F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label15->Location = System::Drawing::Point(13, 230);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(337, 13);
			this->label15->TabIndex = 12;
			this->label15->Text = L"Select The Training Type That Want To Train Your Network :";
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
			this->label9->Location = System::Drawing::Point(13, 163);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(262, 13);
			this->label9->TabIndex = 10;
			this->label9->Text = L"Number Of Neurons Inside Each Hidden Layer :";
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
			this->hidden_layers_num_combo_box->Location = System::Drawing::Point(25, 109);
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
			this->label8->Location = System::Drawing::Point(13, 93);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(162, 13);
			this->label8->TabIndex = 8;
			this->label8->Text = L"Number Of Hidden Layer(s) :";
			// 
			// clear_all
			// 
			this->clear_all->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->clear_all->Location = System::Drawing::Point(275, 397);
			this->clear_all->Name = L"clear_all";
			this->clear_all->Size = System::Drawing::Size(90, 59);
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
			this->class_id_combo_box->Location = System::Drawing::Point(25, 361);
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
			this->label2->Location = System::Drawing::Point(8, 345);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(357, 13);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Select Class id And Click To Add a Sample in Coordinate Plane:";
			// 
			// set_button
			// 
			this->set_button->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->set_button->Location = System::Drawing::Point(16, 295);
			this->set_button->Name = L"set_button";
			this->set_button->Size = System::Drawing::Size(355, 25);
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
			this->total_classNum_combo_box->Location = System::Drawing::Point(25, 45);
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
			this->label1->Location = System::Drawing::Point(13, 29);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(295, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Outputs (Total Number of Classes You Want To Use) :";
			// 
			// groupBox2
			// 
			this->groupBox2->Controls->Add(this->output_layer_label);
			this->groupBox2->Controls->Add(this->hidden_layers_label);
			this->groupBox2->Controls->Add(this->input_label);
			this->groupBox2->Controls->Add(this->label14);
			this->groupBox2->Controls->Add(this->label13);
			this->groupBox2->Controls->Add(this->label12);
			this->groupBox2->Controls->Add(this->label11);
			this->groupBox2->Controls->Add(this->Error_lable);
			this->groupBox2->Controls->Add(this->label10);
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
			this->groupBox2->Location = System::Drawing::Point(818, 497);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(392, 232);
			this->groupBox2->TabIndex = 6;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Information";
			// 
			// output_layer_label
			// 
			this->output_layer_label->AutoSize = true;
			this->output_layer_label->Font = (gcnew System::Drawing::Font(L"Arial", 8.25F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->output_layer_label->ForeColor = System::Drawing::Color::Red;
			this->output_layer_label->Location = System::Drawing::Point(296, 197);
			this->output_layer_label->Name = L"output_layer_label";
			this->output_layer_label->Size = System::Drawing::Size(11, 13);
			this->output_layer_label->TabIndex = 20;
			this->output_layer_label->Text = L"-";
			// 
			// hidden_layers_label
			// 
			this->hidden_layers_label->AutoSize = true;
			this->hidden_layers_label->Font = (gcnew System::Drawing::Font(L"Arial", 8.25F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->hidden_layers_label->ForeColor = System::Drawing::Color::Green;
			this->hidden_layers_label->Location = System::Drawing::Point(158, 197);
			this->hidden_layers_label->Name = L"hidden_layers_label";
			this->hidden_layers_label->Size = System::Drawing::Size(11, 13);
			this->hidden_layers_label->TabIndex = 19;
			this->hidden_layers_label->Text = L"-";
			// 
			// input_label
			// 
			this->input_label->AutoSize = true;
			this->input_label->Font = (gcnew System::Drawing::Font(L"Arial", 8.25F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->input_label->ForeColor = System::Drawing::Color::Blue;
			this->input_label->Location = System::Drawing::Point(22, 197);
			this->input_label->Name = L"input_label";
			this->input_label->Size = System::Drawing::Size(11, 13);
			this->input_label->TabIndex = 18;
			this->input_label->Text = L"-";
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->Font = (gcnew System::Drawing::Font(L"Sitka Display", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label14->ForeColor = System::Drawing::Color::Red;
			this->label14->Location = System::Drawing::Point(280, 171);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(37, 16);
			this->label14->TabIndex = 17;
			this->label14->Text = L"output";
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Font = (gcnew System::Drawing::Font(L"Sitka Display", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label13->ForeColor = System::Drawing::Color::Green;
			this->label13->Location = System::Drawing::Point(137, 171);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(65, 16);
			this->label13->TabIndex = 16;
			this->label13->Text = L"hidden layer";
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Font = (gcnew System::Drawing::Font(L"Sitka Display", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label12->ForeColor = System::Drawing::Color::Blue;
			this->label12->Location = System::Drawing::Point(8, 171);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(32, 16);
			this->label12->TabIndex = 15;
			this->label12->Text = L"input";
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Font = (gcnew System::Drawing::Font(L"Sitka Small", 8.25F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label11->Location = System::Drawing::Point(7, 144);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(141, 16);
			this->label11->TabIndex = 14;
			this->label11->Text = L"Network Architecture :";
			// 
			// Error_lable
			// 
			this->Error_lable->AutoSize = true;
			this->Error_lable->Font = (gcnew System::Drawing::Font(L"Arial", 8.25F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->Error_lable->Location = System::Drawing::Point(63, 94);
			this->Error_lable->Name = L"Error_lable";
			this->Error_lable->Size = System::Drawing::Size(11, 13);
			this->Error_lable->TabIndex = 13;
			this->Error_lable->Text = L"-";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Font = (gcnew System::Drawing::Font(L"Sitka Small", 8.25F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label10->Location = System::Drawing::Point(8, 91);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(49, 16);
			this->label10->TabIndex = 12;
			this->label10->Text = L"Error :";
			// 
			// cycle_count_label
			// 
			this->cycle_count_label->AutoSize = true;
			this->cycle_count_label->Font = (gcnew System::Drawing::Font(L"Arial", 8.25F, static_cast<System::Drawing::FontStyle>((System::Drawing::FontStyle::Bold | System::Drawing::FontStyle::Italic)),
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->cycle_count_label->Location = System::Drawing::Point(233, 119);
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
			this->label7->Location = System::Drawing::Point(7, 116);
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
			this->x2_label->Location = System::Drawing::Point(267, 65);
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
			this->x1_label->Location = System::Drawing::Point(137, 63);
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
			this->label6->Location = System::Drawing::Point(97, 60);
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
			this->label5->Location = System::Drawing::Point(230, 62);
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
			this->label4->Location = System::Drawing::Point(6, 60);
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
			this->ClientSize = System::Drawing::Size(1234, 761);
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
			train_type = Training_type_combo_box->SelectedIndex;


			// the rows of our weight matrix is equal to total class number and the colums are equal to inputs + 1 ( because we are going to choose our input from coordinate palne
			// the input number is always equal to 2. the +1  is because we also add bias constant to our input matrix)
			weight_array_length = total_class_number * (dimension + 1);
			weight_array = new double[weight_array_length];
			set_network_architecture();
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
		// enable train type combo box , so user can specify the way they want to train the network (SGD or SGD_M)
		Training_type_combo_box->Enabled = true;
		Training_type_combo_box->SelectedIndex = 0;

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

	void set_network_architecture() {
		// set input (input is not a layer because we get the data from user)
		input_label->Text = Convert::ToString(dimension);

		// set hidden layer(s)
		String^ hidden_layers_text = ""; // multiply by 2 because we put space between each character
		for (int i = 0; i < number_of_hidden_layers; i++) {
			hidden_layers_text += (neurons_number_in_each_hidden_layer.ToString() + " ");
		}
		hidden_layers_label->Text = Convert::ToString(hidden_layers_text);

		//set output layer
		output_layer_label->Text = Convert::ToString(total_class_number);
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

	// clear coordinate plane by deleting all the lines and points 
	private: System::Void clear_all_Click(System::Object^ sender, System::EventArgs^ e) {
		Coordinate_plane_PictureBox->Refresh();
		total_points = 0;
		if(points != NULL){
			delete[]points;
			points = NULL;
		}
	}
//##############################################################################################################################################################################################################
	
	private: System::Void stochasticGradientDescentSGDToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {

		/*total_points = 3;
		points[0].x_coordinates[0] = 10;
		points[0].x_coordinates[1] = 10;
		points[0].class_id = 0;
		
		points[1].x_coordinates[0] = 20;
		points[1].x_coordinates[1] = 15;
		points[1].class_id = 1;

		points[2].x_coordinates[0] = 30;
		points[2].x_coordinates[1] = 20;
		points[2].class_id = 0;*/

		//points[3].x_coordinates[0] = 2;
		//points[3].x_coordinates[1] = -11;
		//points[3].class_id = 0;

		//points[4].x_coordinates[0] = -1;
		//points[4].x_coordinates[1] = 3;
		//points[4].class_id = 1;

		Neural_Network* my_network = (Neural_Network *)malloc(sizeof(Neural_Network));
		create_network(my_network, dimension, number_of_hidden_layers, neurons_number_in_each_hidden_layer, total_class_number, train_type);

		/*Layer * all_layers = my_network->layers;
		all_layers[0].weights[0] = 0.6;
		all_layers[0].weights[1] = 0.3;
		all_layers[0].weights[2] = 0.2;
		all_layers[0].weights[3] = 0.5;
		all_layers[0].weights[4] = 0.8;
		all_layers[0].weights[5] = 0.2;
		all_layers[0].weights[6] = 0.1;
		all_layers[0].weights[7] = 0.9;
		all_layers[0].weights[8] = 0.7;

		all_layers[1].weights[0] = 0.6;
		all_layers[1].weights[1] = 0.3;
		all_layers[1].weights[2] = 0.2;
		all_layers[1].weights[3] = 0.5;
		all_layers[1].weights[4] = 0.8;
		all_layers[1].weights[5] = 0.2;
		all_layers[1].weights[6] = 0.1;
		all_layers[1].weights[7] = 0.9;*/
		z_score_normalization(points, total_points);
		double norm_error = 0.0;
		double max_error = 0.001;
		double total_error;
		int cycles = 100000;
		int cycle_count = 0;

		do {
			total_error = 0.0;
			for (int p = 0; p < total_points; p++) {
				total_error += train(points[p], my_network, my_network->layers, train_type);
			}

			norm_error = RMSE(total_error, total_points, my_network->total_neuron_number);
			Error_lable->Text = Convert::ToString(norm_error);
			Error_lable->Refresh();

			cycle_count += 1;
		} while (norm_error > max_error /*&& cycles > cycle_count*/);

		cycle_count_label->Text = cycle_count.ToString();
		Coordinate_plane_PictureBox->Refresh();

		int min_x, min_y, max_x, max_y;
		min_x = (this->Coordinate_plane_PictureBox->Width) / -2;
		max_x = (this->Coordinate_plane_PictureBox->Width) / 2;

		for (int neuron_index = 0; neuron_index < my_network->layers[0].number_of_neurons; neuron_index++) {

			Pen^ pen;
			switch (neuron_index) {
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

			min_y = find_y_point(min_x, &my_network->layers[0].weights[neuron_index * (dimension + 1)], 100);
			max_y = find_y_point(max_x, &my_network->layers[0].weights[neuron_index * (dimension + 1)], 100);
			Coordinate_plane_PictureBox->CreateGraphics()->DrawLine(pen, (Coordinate_plane_PictureBox->Width / 2) + min_x, (Coordinate_plane_PictureBox->Height / 2) - min_y, (Coordinate_plane_PictureBox->Width / 2) + max_x, (Coordinate_plane_PictureBox->Height / 2) - max_y);

		}

		
		for (int i = 0; i < total_points; i++) {

			int pure_x = points[i].x_coordinates[0]* 100 + (Coordinate_plane_PictureBox->Width / 2);
			int pure_y = (Coordinate_plane_PictureBox->Height / 2) - points[i].x_coordinates[1]*100;

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

	private: System::Void start_training_button_Click(System::Object^ sender, System::EventArgs^ e) {
		Neural_Network* my_network = (Neural_Network*)malloc(sizeof(Neural_Network));
		create_network(my_network, dimension, number_of_hidden_layers, neurons_number_in_each_hidden_layer, total_class_number, train_type);

		z_score_normalization(points, total_points);
		double norm_error = 0.0;
		double max_error = 0.001;
		double total_error;
		int cycles = 100000;
		int cycle_count = 0;

		do {
			total_error = 0.0;
			for (int p = 0; p < total_points; p++) {
				total_error += train(points[p], my_network, my_network->layers, train_type);
			}

			norm_error = RMSE(total_error, total_points, my_network->total_neuron_number);
			Error_lable->Text = Convert::ToString(norm_error);
			Error_lable->Refresh();

			cycle_count += 1;
		} while (norm_error > max_error /*&& cycles > cycle_count*/);

		cycle_count_label->Text = cycle_count.ToString();
		Coordinate_plane_PictureBox->Refresh();

		draw_lines(my_network->layers[0].number_of_neurons, my_network->layers[0].weights);
		draw_points();
	}

//##############################################################################################################################################################################################################

	private :void draw_lines(int number_of_lines, double *weights) {
		int min_x, min_y, max_x, max_y;
		min_x = (this->Coordinate_plane_PictureBox->Width) / -2;
		max_x = (this->Coordinate_plane_PictureBox->Width) / 2;

		for (int line_index = 0; line_index < number_of_lines; line_index++) {

			Pen^ pen;
			switch (line_index) {
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

			min_y = find_y_point(min_x, &weights[line_index* (dimension + 1)], 50);
			max_y = find_y_point(max_x, &weights[line_index * (dimension + 1)], 50);
			Coordinate_plane_PictureBox->CreateGraphics()->DrawLine(pen, (Coordinate_plane_PictureBox->Width / 2) + min_x, (Coordinate_plane_PictureBox->Height / 2) - min_y, (Coordinate_plane_PictureBox->Width / 2) + max_x, (Coordinate_plane_PictureBox->Height / 2) - max_y);

		}
	}

//##############################################################################################################################################################################################################
	
	private: void draw_points() {
		for (int i = 0; i < total_points; i++) {

			int pure_x = points[i].x_coordinates[0] * 50 + (Coordinate_plane_PictureBox->Width / 2);
			int pure_y = (Coordinate_plane_PictureBox->Height / 2) - points[i].x_coordinates[1] * 50;

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


	
};
}
