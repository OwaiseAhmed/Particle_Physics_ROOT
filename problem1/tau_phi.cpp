
void tau_phi()

{

    TH1F *hist_tauphi  = new TH1F("Tau phi", "Tau phi", 100 , -4., 4.);
    
hist_tauphi->GetXaxis()->SetTitle("Tau_phi, radian");


    auto file = TFile::Open("DYJetsToLL.root");

    auto Tree = (TTree*)file->Get("Events");

    uint ntau;
    int nentires = Tree->GetEntries();
    int max = 50;

    float tau_phi[max];

    Tree->SetBranchAddress("nTau", &ntau);
    Tree->SetBranchAddress("Tau_phi", tau_phi);

    for (int i = 0; i < nentires; i++)
    {
        Tree->GetEntry(i);
        for (int j = 0; j < ntau; j++)
        {

            hist_tauphi->Fill(tau_phi[j]);
        }
    }

    TCanvas *c6= new TCanvas();
    hist_tauphi->Draw();

    return;
}
