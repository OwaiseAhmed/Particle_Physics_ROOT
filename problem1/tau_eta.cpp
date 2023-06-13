
void tau_eta()

{

    TH1F *hist_taueta  = new TH1F("Tau eta", "Tau_eta", 48, -6., 6.);

    auto file = TFile::Open("DYJetsToLL.root");

hist_taueta->GetXaxis()->SetTitle("Tau eta");

    auto Tree = (TTree*)file->Get("Events");

    uint ntau;
    int nentires = Tree->GetEntries();
    int max = 50;

    float tau_eta[max];

    Tree->SetBranchAddress("nTau", &ntau);
    Tree->SetBranchAddress("Tau_eta", tau_eta);

    for (int i = 0; i < nentires; i++)
    {
        Tree->GetEntry(i);
        for (int j = 0; j < ntau; j++)
        {

            hist_taueta->Fill(tau_eta[j]);
        }
    }

    TCanvas *c7= new TCanvas();
    hist_taueta->Draw();

    return;
}
